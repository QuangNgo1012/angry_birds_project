#include "level.hpp"

Level::Level() : name_("") {}

//Use to remove object
bool RemoveObject(Object *object)
{
    return object->Broken();
}
Level::Level(std::ifstream& file)
{ 
    char _;
    std::string bird_list;
    std::getline(file, bird_list);
    world_ = new b2World(b2Vec2 (0.0f, -9.8f));
    while (!file.eof())
    {
        char object_type;
        b2BodyDef body_parameters;
        std::string fixture_str;
        int shape_type;
        b2CircleShape circle;
        b2PolygonShape polygon;

        file.get(object_type);
        file.ignore();
        file >> body_parameters.position >> _ >> body_parameters.angle >> _ >> body_parameters.angularVelocity >> _ >> body_parameters.linearVelocity >> _ >> body_parameters.angularDamping >> _ >> body_parameters.linearDamping >> _ >> body_parameters.gravityScale >> _ >> body_parameters.type >> _ >> body_parameters.awake >> _;
        b2Body *body = world_->CreateBody(&body_parameters);
        std::getline(file, fixture_str, '\n');
        std::stringstream fixture(fixture_str);
        b2FixtureDef fixture_parameters;
        fixture >> shape_type >> _;  
        switch (shape_type)
        {
        case b2Shape::Type::e_circle:
        {
            fixture_str = "(0:0);0.3;1;1;0.4;";
            std::stringstream fixture_circle(fixture_str);
            fixture_circle >> circle.m_p >> _ >> circle.m_radius >> _;
            fixture_parameters.shape = &circle;
            fixture_circle >> fixture_parameters.density >> _ >> fixture_parameters.friction >> _ >> fixture_parameters.restitution >> _; 
            break;
            }
            case b2Shape::Type::e_polygon:
            {
            if (object_type == 'O')
            {
                fixture_str ="(0:0);(-0.25:-1.5);(0.25:-1.5);(0.25:1.5);(-0.25:1.5);(6.72623e-44:0);(4.2039e-44:0);(1.12104e-44:0);(7.1999e-38:0);(0:-1);(1:0);(0:1);(-1:0);(0:4.59065e-41);(4.2039e-44:0);(0:0);(0:0);4;0.01;1;0.1;0;";
                std::stringstream fixture_obstacle(fixture_str);
                fixture_obstacle >> polygon.m_centroid >> _;
                for (int i = 0; i < 8; i++)
                {
                    b2Vec2 vertex;
                    fixture_obstacle >> vertex >> _;
                    polygon.m_vertices[i] = vertex; 
                }
                for (int i = 0; i < 8; i++)
                {
                    b2Vec2 normal;
                    fixture_obstacle >> normal >> _;
                    polygon.m_normals[i] = normal;
                }

                fixture_obstacle >> polygon.m_count >> _ >> polygon.m_radius >> _;
                fixture_parameters.shape = &polygon;
                fixture_obstacle >> fixture_parameters.density >> _ >> fixture_parameters.friction >> _ >> fixture_parameters.restitution >> _;
                break;
            }
            else if (object_type == 'G')
            {
                fixture_str ="(0:0);(-50:-1);(50:-1);(50:1);(-50:1);(0:0);(0:-3.44621e-41);(5.56208e+28:4.59065e-41);(1.2857e-39:0);(0:-1);(1:0);(0:1);(-1:0);(0:0);(0:0);(6.0633e-38:0);(6.06114e-38:0);4;0.01;0;0.2;0;";
                std::stringstream fixture_ground(fixture_str);
                fixture_ground >> polygon.m_centroid >> _;
                for (int i = 0; i < 8; i++)
                {
                    b2Vec2 vertex;
                    fixture_ground >> vertex >> _;
                    polygon.m_vertices[i] = vertex; 
                }
                for (int i = 0; i < 8; i++)
                {
                    b2Vec2 normal;
                    fixture_ground >> normal >> _;
                    polygon.m_normals[i] = normal;
                }

                fixture_ground >> polygon.m_count >> _ >> polygon.m_radius >> _;
                fixture_parameters.shape = &polygon;
                fixture_ground >> fixture_parameters.density >> _ >> fixture_parameters.friction >> _ >> fixture_parameters.restitution >> _;
                break;
            }
            }
            default:
            break;
            }
            switch (object_type)
            {
            case 'R':
            case 'C':
            case 'T':
            {
                for (auto type : bird_list)
                {
                    Bird *bird;
                    switch (type)
                    {
                        case 'R':
                        bird = new Red(body, fixture_parameters.shape->m_radius);
                        break;
                    case 'C':
                        bird = new Chuck(body, fixture_parameters.shape->m_radius);
                        break;
                    case 'T':
                        bird = new Terence(body, fixture_parameters.shape->m_radius);
                        break;
                    default:
                        continue;
                    }
                    birds_list_.push_back(bird);
                    fixture_parameters.userData.pointer = reinterpret_cast<uintptr_t>(bird);
                }
                break;

            }
            case 'G':
            {
                Ground *g = new Ground(body);
                fixture_parameters.userData.pointer = reinterpret_cast<uintptr_t>(g);
                objects_list_.push_back(g);
                break;
            }
            case 'P':
            {
                Pig *p = new Pig(body, fixture_parameters.shape->m_radius);
                fixture_parameters.userData.pointer = reinterpret_cast<uintptr_t>(p);
                objects_list_.push_back(p);
                break;
            }
            case 'O':
            {

                const b2PolygonShape *shape = static_cast<const b2PolygonShape *>(fixture_parameters.shape);
                float min_w, max_w, min_h, max_h;
                min_w = max_w = min_h = max_h = 0;
                for (int i = 0; i < shape->m_count; i++)
                {
                    b2Vec2 vertex = shape->m_vertices[i];
                    min_w = std::min(min_w, vertex.x);
                    max_w = std::max(max_w, vertex.x);
                    min_h = std::min(min_h, vertex.y);
                    max_h = std::max(max_h, vertex.y);
                }
                float width = max_w - min_w;
                float height = max_h - min_h;
                b2Vec2 dimensions = b2Vec2(width / 2, height / 2);
                Obstacle *w = new Obstacle(body, dimensions.x, dimensions.y);
                fixture_parameters.userData.pointer = reinterpret_cast<uintptr_t>(w);
                objects_list_.push_back(w);
                break;
            }
            default:
                continue;
            }
            body->CreateFixture(&fixture_parameters);
        }
    


}
void Level::SetBird()
{

    if (birds_list_.size() > 1)
    {
        birds_list_.pop_front();
    }
    if (birds_list_.front()->IsThrown())
    {
        is_ended_ = true;
    }
    b2Body *body = GetBird()->GetBody();
    body->SetGravityScale(0);
    body->SetTransform(b2Vec2(3,2.5f), 0);
}
bool Level::RenderLevel(sf::RenderWindow &window){
    //Draw Slingshot
    sf::RectangleShape slingshot(sf::Vector2f(100.0f, 100.0f));
    sf::Texture slingshot_texture;
    slingshot_texture.loadFromFile("src/images/slingshot.png");
    slingshot.setTexture(&slingshot_texture);
    slingshot.setScale(1, 1.5f);
    slingshot.setOrigin(50, 30);
    slingshot.setPosition(300.0f,650.0f);
    window.draw(slingshot);

    //Calculate Score
    for (b2Contact *contact_objects = world_->GetContactList(); contact_objects; contact_objects = contact_objects->GetNext())
    {
        b2Contact *contact_object = contact_objects;
        Object *objectA = reinterpret_cast<Object *>(contact_object->GetFixtureA()->GetUserData().pointer);
        Object *objectB = reinterpret_cast<Object *>(contact_object->GetFixtureB()->GetUserData().pointer);
        score_ = score_ + objectA->Attack(objectB->GetBody()->GetLinearVelocity().Length());
        score_ = score_ + objectB->Attack(objectA->GetBody()->GetLinearVelocity().Length());
    }

    //Remove Object when destroyed
    for (auto object : objects_list_)
    {
        if (object->Broken())
        {
            world_->DestroyBody(object->GetBody());
        }
    }
    objects_list_.remove_if(RemoveObject);

    //Check level's state
    if (CountPigs() == 0 && !IsLevelEnded())
    {
        is_win_= true;
        is_ended_ = true;
        score_ = score_ + (static_cast<int>(birds_list_.size()) - 1) * 1000;
    }
    bool moving = false;

    //Draw objects
    for (auto object : objects_list_)
    {
        b2Body *body = object->GetBody();
        b2Vec2 position = body->GetPosition();
        sf::Sprite sprite = object->GetSprite();
        sprite.setPosition(position.x*100,900-(100*position.y));
        sprite.setRotation(body->GetAngle()*(180.0f / M_PI)*-1.0f);
        window.draw(sprite);
        moving = moving || body->IsAwake();
    }
    b2Body *body = GetBird()->GetBody();
    b2Vec2 position = body->GetPosition();
    sf::Sprite sprite = GetBird()->GetSprite();
    sprite.setPosition(position.x*100,900-(100*position.y));
    sprite.setRotation(-body->GetAngle()*(180.0f / M_PI));
    window.draw(sprite);

    //Stop birds when out of bound
    bool IsOut = !(position.x <(1600 * 1.5f)/100 && position.x > -1);
    if (IsOut)
    {
        body->SetLinearVelocity(b2Vec2(0, 0));
        body->SetAngularVelocity(0.f);
        return false || moving;
    }
    return moving || body->IsAwake();
}

int Level::CountPigs()
{
    int count = 0;
    for (const auto &object : objects_list_)
    {
        if (Pig *pig = dynamic_cast<Pig *>(object))
        {
            count++;
        }
    }
    return count;
}

void Level::ThrowBird(b2Vec2 force){
    if (!IsLevelEnded())
    {
        b2Body *bird = GetBird()->GetBody();
        bird->SetGravityScale(1);
        bird->ApplyLinearImpulseToCenter(force, true);
        GetBird()->Throw();
    }
}