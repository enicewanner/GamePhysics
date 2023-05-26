#pragma once
#include "../Physics/Shapes/Body.h"
#include "../Physics/Constraints/Joint.h"
#include <list>
#include <vector>

class World
{
public:
	~World();

	void Step(float dt);
	void Draw(class Graphics* graphics);

	void AddBody(Body* body);
	void RemoveBody(Body* body);

	void AddJoint(class Joint* joint);
	void RemoveJoint(class Joint* joint);

	void AddForceGenerator(class ForceGenerator* forceGenerator);

public:
	static glm::vec2 gravity;

private:
	std::list<Body*> m_bodies;
	std::list<Joint*> m_joints;
	std::vector<class ForceGenerator*> m_forceGenerators;

};