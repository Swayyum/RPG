#include "lands.h"

using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case SWAMP:
            return new Swamp;
            break;
        case BADLANDS:
            return new Badlands;
            break;
        case BEACH:
            return new Beach;
            break;
        case SAVANNA:
            return new Savanna;
            break;
        case MOUNTAINS:
            return new Mountains;
            break;
        default:
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    p.setThirst(p.getThirst() - 2);

    return description;
}

//Swamp
string Swamp::getShortDescription(){
    return "swamp";
}

string Swamp::getLongDescription(){
    return "You arrive at a mushy freshwater swamp";
}

string Swamp::visit(Player& p){
    string description = "You drink water from the swamp, but its not good";
    p.setThirst(p.getThirst() + 0);
    
    int chance = rand() % 100;
    
    // Chance to find fish
    if(chance > 50){
        description = "You caught some fish in the swamp!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    //chance to find fish but loose it 
    if(chance > 50){
        description = "You caught some fish in the swamp but a bird stole it!";
        p.setHunger(p.getHunger() - 2);
        return description;
    }
    // Chance to get sick from swamp water
    if(chance > 50){
        description = "You get sick from drinking swamp water";
        p.setHealth(p.getHealth() - 1);
    }
    
    return description;
}


//Badlands
string Badlands::getShortDescription(){
    return "Badlands";
}

string Badlands::getLongDescription(){
    return "You arrive at a massive dry badlands";
}

string Badlands::visit(Player& p){
    string description = "You cannot find anywater!";
    p.setThirst(p.getThirst() - 2);
    int chance = rand() % 100;
    
    // Chance to find a rat
    if(chance > 50){
        description = "You cannot find any food!";
        p.setHunger(p.getHunger() - 1);
        return description;
    }
    
    // Chance to get attacked by a snake
    if(chance > 50){
        description = "You get bit by a venomous snake!!!";
        p.setHealth(p.getHealth() - 2);
    }
    return description;
}


//Beach
string Beach::getShortDescription(){
    return "beach";
}

string Beach::getLongDescription(){
    return "You arrive beautiful long stretch of a beach";
}

string Beach::visit(Player& p){
    string description = "You drink water from the ocean but its salty!";
    p.setThirst(p.getThirst() + 1);
    int chance = rand() % 100;
    
    // Chance to find crabs on the shore
    if(chance < 5){
        description = "You found a crab on the shore and cooked it";
        p.setHunger(p.getHunger() + 3);
        return description;
    }
    
    // Chance to get stung by a jellyfsih
    if(chance > 50){
        description = "You get stung by a jellyfish";
        p.setHealth(p.getHealth() - 2);
    }
    return description;
}


//Savanna
string Savanna::getShortDescription(){
    return "savanna";
}

string Savanna::getLongDescription(){
    return "You arrive at huge land of open savanna.";
}

string Savanna::visit(Player& p){
    string description = "You find scarce drops of water";
    p.setThirst(p.getThirst() + 1);
    int chance = rand() % 100;
    
    // Chance to a deer
    if(chance > 50){
        description = "You found a deer killed and left by a lion";
        p.setHunger(p.getHunger() + 3);
        return description;
    }
    
    // Chance to get atatcked by a lion
    if(chance < 10 && chance > 5){
        description = "You got attacked by a lion, the deer was onl bait!";
        p.setHealth(p.getHealth() - 8);
    }
    return description;
}

//Mountains
string Mountains::getShortDescription(){
    return "mountains";
}

string Mountains::getLongDescription(){
    return "You arrive at tall, cold and beautifu mountains.";
}

string Mountains::visit(Player& p){
    string description = "You drink from the melting galcier ";
    p.setThirst(p.getThirst() + 3);
    int chance = rand() % 100;
    
    // No food
    if(chance > 50){
        description = "You found no food, and you are already tired from walking..";
        p.setHunger(p.getHunger() - 2);
        return description;
    }
    
    // Chance to slip and fall
    if(chance < 10 && chance > 5){
        description = "You got stepped on the wrong footing and fell";
        p.setHealth(p.getHealth() - 5);
    }
    return description;
}