#include "Player.h"
#include "Bullet.h"

/*Implementation av Actor. En karakt�r som styrs av spelaren och har olika kontroller beroende p� vilket team den tillh�r (0 eller 1)*/
Player::Player(int posX, int posY,int team) : Actor(posX, posY, 32, 32)
{
	setTeam(team);
	setSprite(32, 0,32,32);
	if (getTeam() == 1)
	setSprite(96, 32, 32, 32);
}
/*definierar Players beteende*/

void Player::act()
{
	if (getTeam() == 0)
	move();
	if (getTeam() == 1)
	move2();

	//reglerar anv�ndadet av PewPew()
	if (cooldown != 0)
		cooldown--;

	checkCollision();
	
}
//kontroller f�r spelare 1
void Player::move()
{
	if (getRight() == true)
	{
		setX(getX() + 3);
		setSprite(32, 0, 32, 32);
		direction = 1;
	}
	if (getLeft() == true)
	{
		setX(getX() - 3);
		setSprite(96, 0, 32, 32);
		direction = 3;
	}
	if (getUp() == true)
	{
		setY(getY() - 3);
		setSprite(0, 0, 32, 32);
		direction = 0;
	}
	if (getDown() == true)
	{
		setY(getY() + 3);
		setSprite(64, 0, 32, 32);
		direction = 2;
	}
	if (getZero() == true)
		PewPew();

}
//controller f�r spelare 2
void Player::move2()
{
	if (getD() == true)
	{
		setX(getX() + 3);
		setSprite(32, 32, 32, 32);
		direction = 1;
	}
	if (getA() == true)
	{
		setX(getX() - 3);
		setSprite(96, 32, 32, 32);
		direction = 3;
	}
	if (getW() == true)
	{
		setY(getY() - 3);
		setSprite(0, 32, 32, 32);
		direction = 0;
	}
	if (getS() == true)
	{
		setY(getY() + 3);
		setSprite(64, 32, 32, 32);
		direction = 2;
	}
	if (getSpace() == true)
		PewPew();
}
//kollar om n�gon actor kolliderar med player.
void Player::checkCollision()
{
	std::vector<Actor*> collideVector = gameEngine->intersections(getPosition()); //h�mtar en vector fr�n gameEngine med alla actors som krockar med player
	
	//itererar genom alla actors i listan f�r att se om n�gon �r en farlig fiende(h�r definierat som inte p� det egna laget)
	int nextActor = 0;
	while (nextActor < collideVector.size())
	{
		if (collideVector[nextActor]->getTeam() != getTeam())
		{
			gameEngine->removeActor(getID()); //tar bort sig sj�lv fr�n motorn
			delete this; //tar bort sig sj�lv fr�n minnet
		}
		nextActor++;

	}
}
/*skapar kulor som f�rdas i samma rikning som player*/
void Player::PewPew()
{
	if(cooldown == 0)
	{
		Bullet* bullet = new Bullet(getX() + 13, getY() + 13,direction, getTeam());
		gameEngine->add(bullet, gameEngine);
		cooldown = 10;
	}
	
	
}
Player::~Player()
{

}
