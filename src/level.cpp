#include "level.hpp"
Level::Level(std::ifstream& file){
    mainWorld_ = new b2World(b2Vec2(0, -9.8f));
    
    if(file.rdstate() & (file.failbit | file.badbit)){

        std::cerr << "Failed" << std::endl;

    }else{
        int count = 0;
        
        while(!file.eof()){
            std::string line;
            std::vector<std::string> storage;
            std::getline(file, line);

            if(count == 0){

                name_ = line;


            }else{
                std::stringstream ss(line);
                std::string item;
                while(std::getline(ss,item,'@')){
                    storage.push_back(item);
                }
                createElements(storage);



            }

        }

    }


}

void Level::createElements(std::vector<std::string>& storage){
    
    int len = storage.size();
    
    if(storage[0]=="R" || storage[0]=="C" || storage[0]=="T"){

        int i = 1;
        
        while(i<len){

            std::string parsedRadius = storage[i];
            std::string parsedXCoord = storage[i+1];
            std::string parsedYCoord = storage[i+2]; 
            float radius = std::stof(parsedRadius);
            float XCoord = std::stof(parsedXCoord);
            float YCoord = std::stof(parsedYCoord);
            b2Body* body = CreateCircle(radius,XCoord,YCoord,24,24);
            Bird* playerBird;
            if(storage[0] == "R"){

                playerBird = new Red(body,radius);

            }else if(storage[0]=="C"){

                playerBird = new Chuck(body, radius);

            }else{

                playerBird = new Terence(body, radius);

            }

            birdStore.push_back(playerBird);

            
            i += 3;
        }

    }else if(storage[0]=="P"){
        int i = 1;
        while(i<len){
            std::string parsedRadius = storage[i];
            std::string parsedXCoord = storage[i+1];
            std::string parsedYCoord = storage[i+2]; 
            float radius = std::stof(parsedRadius);
            float XCoord = std::stof(parsedXCoord);
            float YCoord = std::stof(parsedYCoord);
            b2Body* body = CreateCircle(radius,XCoord,YCoord,24,24);
            Pig* playerPig = new Pig( body, radius);
            pigStore.push_back(playerPig);
            i += 3;




        }

    }else{
        int i = 1;
        while(i<len){
            std::string parsedWidth = storage[i];
            std::string parsedHeight = storage[i+1];
            std::string parsedXCoord = storage[i+2];
            std::string parsedYCoord = storage[i+3];
            float width = std::stof(parsedWidth);
            float height = std::stof(parsedHeight);
            float XCoord = std::stof(parsedXCoord);
            float YCoord = std::stof(parsedYCoord);
            b2Body *boxBody = CreateObstacle(width,height,XCoord,YCoord,24,24);

            Obstacle* playerObstacle = new Obstacle(boxBody, width,height);

            obstacleStore.push_back(playerObstacle);

            i += 4;  


        }


    }




}

void Level::RenderLevel(sf::RenderWindow &window){
    for (auto birdIt : birdStore){
        b2Vec2 pos = birdIt->GetBody()->GetPosition();
        sf::Sprite sprite = birdIt->GetSprite();
        sprite.setPosition(pos.x * PPM, WINDOW_HEIGHT - pos.y * PPM);
        sprite.setRotation(-1 * birdIt->GetBody()->GetAngle() * DEG_PER_RAD);
        window.draw(sprite);

    }

    for(auto obsIT: obstacleStore){
        b2Vec2 pos = obsIT->GetBody()->GetPosition();
        sf::Sprite sprite = obsIT->GetSprite();
        sprite.setPosition(pos.x * PPM, WINDOW_HEIGHT - pos.y * PPM);
        sprite.setRotation(-1 * obsIT->GetBody()->GetAngle() * DEG_PER_RAD);
        window.draw(sprite);
    }

    for(auto pigIt : pigStore){
        b2Vec2 pos = pigIt->GetBody()->GetPosition();
        sf::Sprite sprite = pigIt->GetSprite();
        sprite.setPosition(pos.x * PPM, WINDOW_HEIGHT - pos.y * PPM);
        sprite.setRotation(-1 * pigIt->GetBody()->GetAngle() * DEG_PER_RAD);
        window.draw(sprite);
    }


    window.display();







}

void Level::ThrowBird(Bird* bird, b2Vec2 force){
    bird->GetBody()->ApplyForceToCenter(force, true);
}


b2Body* Level::CreateCircle(float radius, float XCoord, float YCoord, float density, float friction){
    
    // create circle shape
    b2CircleShape circle;
    circle.m_p = b2Vec2(0,0);
    circle.m_radius = radius/PPM;
    
    // create fixture
    
    b2FixtureDef fixtureDef;
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    fixtureDef.shape = &circle;
    
    // create bodydef

    b2BodyDef bodyDef;
    bodyDef.position.Set(XCoord/PPM,YCoord/PPM);
    bodyDef.type = b2_dynamicBody;
    
    //create body in the main Box2D world
    
    b2Body *body = mainWorld_->CreateBody(&bodyDef);
    body->CreateFixture(&fixtureDef);  

    return body;  
}

b2Body* Level::CreateObstacle(float width, float height, float XCoord, float YCoord,float density, float friction){

    b2BodyDef boxBodyDef;
    boxBodyDef.position.Set(XCoord / PPM, YCoord / PPM);
    boxBodyDef.type = b2_dynamicBody;
    b2PolygonShape boxShape;
    boxShape.SetAsBox(width / 2 / PPM, height / 2 / PPM);
    b2FixtureDef fixtureDef;
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    fixtureDef.shape = &boxShape;
    b2Body *boxBody = mainWorld_->CreateBody(&boxBodyDef);
    boxBody->CreateFixture(&fixtureDef);

    return boxBody;

}