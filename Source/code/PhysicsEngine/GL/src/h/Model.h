#pragma once

#include "glHeader.h"
#include "Controls.h"
#include "PointCloud.h"
#include "World.h"
#include "btFractureBody.h"

#include <btBulletDynamicsCommon.h>
#include <iostream>

using namespace glm;

class World;
class Controls;
/**
	This class just handles the model transformations and also holds its
	 own model data. Knows which shader to use on itslef
*/
class Model
{
	public:
		Model(Model * m, World * w);
		Model(PointCloud p, GLuint shade, World * w);
		Model(std::string path, GLuint shade, World * w, bool tessalate = false);

		~Model();

		// ----- Setters -----
		void setVertexData(GLfloat * data);
		void setColorData(GLfloat * data);
		// -------------------

		// ----- Getters -----
		GLfloat * getShapeData();
		GLfloat * getColorData();
		GLfloat * getNormalData();
		GLuint getShader();

		uint getFaceCount();
		uint getVertexCount();

		vec3 getPosition();
		vec3 getScale();
		float getRotation();
		mat4 getTransform();

		btRigidBody * getRigidBody();
		btCollisionShape * getCollisionShape();
		float getMass();
		float getFriction();
		float getRollingFriction();
		float getRestitution();

		std::string getType();
		// -------------------

		// ----- Setters -----
		void setColor(float r, float g, float b);
		void randomizeColor();
		void changeColorOnGround(bool c);


		void setTransform(mat4 trans);
		void setPosition(vec3 p);
		void setRotation(float r);
		void setScale(vec3 s);


		void setShader(GLuint shade);


		void setCollisionShape(btCollisionShape * shape);
		void setMass(float m);
		void setFriction(float f);
		void setRollingFriction(float f);
		void setRestitution(float r);

		void setIndex();
		void setType(std::string t);
		// -------------------

		// ----- Draw -----
		void draw(Controls * controls);
		void transformDraw(Controls * controls, btTransform trans);
		void initBuffers();
		// ----------------

		// ----- Other -----
		std::string toString();
		void printNormals();
		void calcTriangleCollisionMesh();
		void configureRigidBody();
		// -----------------

	private:
		bool isCopy;

		GLfloat * shapeData;
		GLfloat * colorData;
		GLfloat * normalData;

		GLuint verticies;
		GLuint colors;
		GLuint normals;

		mat4 transform;

		vec3 position;
		vec3 m_scale;
		float rotation;

		GLuint MatrixID;
		GLuint ViewMatrixID;
		GLuint ModelMatrixID;

		GLuint shader;		

		bool setupComplete;

		uint faceCount;
		uint vertexCount;


		// ----- Physics Variables -----
		
		// Defaults to a Cube (1, 1, 1)
		btCollisionShape * collisionShape;

		// Rigid Body
		btFractureBody * rigidBody;

		// Motion State
		btDefaultMotionState* motionState;


		float mass;
		float friction;
		float rollingFriction;
		float resititution;

		bool changeColor;

		World * world;
		// -----------------------------
		

		// ----- Indexing -----
		int index; // Set elsewhere
		std::string type;
		// --------------------
};