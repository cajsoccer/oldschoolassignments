#include <iostream>
#include <string>
#include <math.h>

bool determinePlayerState(const int &id);
double determineDistance(const int &monstX, const int &monstY, const int &playerX, const int &playerY);
int determinePlayerArrival(const double &d, const int &Tn, const int &S);
std::string determineCapProb(const int &Tg, const int &Ta, const int &Te, const bool &isLucky);

int main()
{
    int monstX = 0;
    int monstY = 0;
    int monstAppTime = 0;
    int monstPosExistTime = 0;
    int playerId = 0;
    int playerX = 0;
    int playerY = 0;
    int playerNoticeTime = 0;
    int walkSpeed = 0;
    bool isLucky = false;
    double dist = 0.0;
    int Tg = 0;
    std::string prob = "";
    std::cout << "Hello and welcome to the Monster Capture Possibility Calculator." << std::endl;
    std::cout << "Please enter the latitude of the monster (1-10):";
    std::cin >> monstY;
    std::cout << "Please enter the longitude of the monster (1-10):";
    std::cin >> monstX;
    std::cout << "Please enter the time of the monster appearing (1-1440):";
    std::cin >> monstAppTime;
    std::cout << "Please enter the possible time of that the monster will exist for (10-59):";
    std::cin >> monstPosExistTime;
    std::cout << "Please enter the player's ID (8 digits):";
    std::cin >> playerId;
    std::cout << "Please enter the time of the player noticing monster (1-1440 and greater than the time the monster appears):";
    std::cin >> playerNoticeTime;
    std::cout << "Please enter the latitude of the player (1-10):";
    std::cin >> playerY;
    std::cout << "Please enter the longitude of the player (1-10):";
    std::cin >> playerX;
    std::cout << "Please enter the player's walking speed (10-200):";
    std::cin >> walkSpeed;
    isLucky = determinePlayerState(playerId);
    dist = determineDistance(monstX, monstY, playerX, playerY);
    Tg = determinePlayerArrival(dist, playerNoticeTime, walkSpeed);
    prob = determineCapProb(Tg, monstAppTime, monstPosExistTime, isLucky);
    std::string luckPrint = "";
    if (isLucky)
        luckPrint = " lucky";
    else
        luckPrint = " normal";
    std::cout << "Player " << playerId << " who is on the" << luckPrint <<  " list, noticed the monster at time " << playerNoticeTime << ", is " << dist * 1000 << " m away from the monster, and will arrive at time " << Tg << ". The monster's disappear time is about " << monstAppTime + monstPosExistTime << ". So the player will capture this monster with " << prob << " possibility." << std::endl;  
    return 0;
}

bool determinePlayerState(const int &id)
{
    std::string idString = std::to_string(id);
    std::string idStringEnd = "";
    idStringEnd = idString[6];
    idStringEnd = idStringEnd + idString[7];
    int num = std::stoi(idStringEnd);
    if (num > 49) 
        return false;
    else    
        return true;
}

double determineDistance(const int &monstX, const int &monstY, const int &playerX, const int &playerY)
{
    int xDelta = abs(monstX - playerX);
    int yDelta = abs(monstY - playerY);
    double dist = sqrt(pow(xDelta,2) + pow(yDelta,2));
    return dist;
}

int determinePlayerArrival(const double &d, const int &Tn, const int &S)
{
    double Tg = Tn + (1000 * d / S);
    return std::round(Tg);
}

std::string determineCapProb(const int &Tg, const int &Ta, const int &Te, const bool &isLucky)
{
    if (Tg <= Ta + Te)
        return "Definitely";
    else
    {
        if (isLucky)
        {
            if ((Tg - (Ta + Te))/ (double)Te <= 0.1)
                return "Highly Likely";
            else if ((Tg - (Ta + Te))/ (double)Te <= 0.3)
                return "Likely";
            else if ((Tg - (Ta + Te))/ (double)Te <= 0.4)
                return "Unsure";
            else if ((Tg - (Ta + Te))/ (double)Te <= 0.5)
                return "Unlikely";
            else
                return "Highly Unlikely";
        }
        else
        {
            if ((Tg - (Ta + Te))/ (double)Te <= 0.05)
                return "Highly Likely";
            else if ((Tg - (Ta + Te))/ (double)Te <= 0.2)
                return "Likely";
            else if ((Tg - (Ta + Te))/ (double)Te <= 0.35)
                return "Unsure";
            else if ((Tg - (Ta + Te))/ (double)Te <= 0.4)
                return "Unlikely";
            else
                return "Highly Unlikely";
        }
    }
}