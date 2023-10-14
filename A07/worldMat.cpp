#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_RADIANS

//The application calls procedure MakeWorldMatrixEuler(…) which must create and return a
//glm::mat4 world matrix.It receives as input a glm::vec3 vector called pos, which contains
//the location of the object.The rotation of the object is instead contained in glm::vec3 YPR


// Create a world matrix using position, Euler angles, and size
// Euler angles are passed in YPR parameter:
// YPR.x : Yaw
// YPR.y : Pitch
// YPR.z : Roll
glm::mat4 MakeWorldMatrixEuler(glm::vec3 pos, glm::vec3 YPR, glm::vec3 size) {
	glm::mat4 Mw =
		glm::translate(glm::mat4(1.0), glm::vec3(pos.x, pos.y, pos.z)) *
		glm::rotate(glm::mat4(1.0), glm::radians(YPR.x), glm::vec3(0, 1, 0)) *
		glm::rotate(glm::mat4(1.0), glm::radians(YPR.y), glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1.0), glm::radians(YPR.z), glm::vec3(0, 0, 1)) *
		glm::scale(glm::mat4(1.0), glm::vec3(size.x, size.y, size.z));
	
	
	return Mw;
}

// MW = T(px, py, pz) * R(y) * R(x) * R(z) * S(sx, sy, sz)

//The application calls procedure MakeWorldMatrixQuat(…) which must create and return a
//glm::mat4 world matrix.It receives as input a glm::vec3 vector called pos, which contains
//the location of the object.The rotation of the object is instead contained in quaternion
//glm::quat rQ.Scaling factors along the three main directions are contained in glm::vec3
//size.


// Create a world matrix using position, quaternion angles, and size
glm::mat4 MakeWorldMatrixQuat(glm::vec3 pos, glm::quat rQ, glm::vec3 size) {
	glm::mat4 Mw =
		glm::translate(glm::mat4(1.0), glm::vec3(pos.x, pos.y, pos.z)) *
		glm::mat4(rQ)*
		glm::scale(glm::mat4(1.0), glm::vec3(size.x, size.y, size.z));

		

	return Mw;
}

// MW = T(px, py, pz) * R(q) * S(sx, sy, sz)