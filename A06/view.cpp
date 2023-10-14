 
//VIEW PROJECTION MATRIX
//it allows us to find the normalized screen
//coordinates of the points in space, as seen by the considered camera: It transforms a point from world coordinates (homogeneous coordinates), to 3D normalized screen coordinates(cartesian



//CAMERA MATRIX: MC = T(cx, cy, cz) ? Ry(?) ? Rx(?) ? Rz(?) => MV = MC^-1 = Rz (?? ) ? Rx (?? ) ? Ry (?? ) ?T(?cx,?cy,?cz )

// Create a look in direction matrix
 // Pos    -> Position of the camera
 // Angs.x -> direction (alpha)
 // Angs.y -> elevation (beta)
 // Angs.z -> roll (rho)

glm::mat4 LookInDirMat(glm::vec3 Pos, glm::vec3 Angs) {	
	//Create the VIEW MATRIX

	//POS contains the location of the camera (cx, cy, cz)
	//The direction where the camera is aiming is in ANGS //Angs.x = alpha, Angs.y = beta, Angs.z = rho

	glm::mat4 Mv =
		glm::rotate(glm::mat4(1.0), (-Angs.z), glm::vec3(0, 0, 1)) *
		glm::rotate(glm::mat4(1.0), (-Angs.y), glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1.0), (-Angs.x), glm::vec3(0, 1, 0)) *
		glm::translate(glm::mat4(1.0), glm::vec3(-Pos.x, -Pos.y, -Pos.z));
	return Mv;
}

 // Create a look at matrix
 // Pos    -> Position of the camera (c) cx, cy, cz
 // aim    -> Posizion of the target (a) ax, ay, az
 // Roll   -> roll (rho)
 // vector u is 0, 1, 0
glm::mat4 LookAtMat(glm::vec3 Pos, glm::vec3 aim, float Roll) {
	
	glm::mat4 Mv = glm::lookAt(glm::vec3(Pos.x, Pos.y, Pos.z),
		glm::vec3(aim.x, aim.y, aim.z),
		glm::vec3(0, 1, 0));


	return glm::rotate(glm::mat4(1.0), (-Roll), glm::vec3(0, 0, 1)) * Mv;

	// The camera roll is passed as an extra floating point
	//parameter Roll.Although roll is not generally included in the Look - at view matrix model, it can
	//	be implement in one of two different ways :
	//1. Changing the direction of the up vector, according to the roll angle.
	//	2. Placing a rotation along the z - axis of - r after transformation of the view matrix created
	//	with the technique shown during the lessons.
}



