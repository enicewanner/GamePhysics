#pragma once
#include "Test.h"

class JointTest : public Test
{
public:
	void Initialize() override;
	//void Run() override;

	void Update();

	// Inherited via Test
	virtual void FixedUpdate() override;

	virtual void Render() override;

private:
	class Body* m_anchor{ nullptr };
	int count = 0;

};