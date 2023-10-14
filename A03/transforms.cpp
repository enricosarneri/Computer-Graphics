	// Rotate 45 degrees around an arbitrary axis passing through (1,0,-1). The x-axis can be aligned to the arbitrary axis after a rotation of 30 degrees around the z-axis, and then -60 degrees around the y-axis.
	
	glm::mat4 tr1 = glm::translate(glm::mat4(1), glm::vec3(1, 0, -1));
	glm::mat4 tr1_inv = inverse(tr1);

	glm::mat4 rot_y = glm::rotate(glm::mat4(1), glm::radians(-60.0f), glm::vec3(0, 1, 0)); // R(y-axis)
	glm::mat4 rot_y_inv = inverse(rot_y);

	glm::mat4 rot_z = glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(0, 0, 1)); //R(z-axis)
	glm::mat4 rot_z_inv = inverse(rot_z);

	glm::mat4 rot_x = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1, 0, 0)); // R(arbitrary - axis) //we make the arbitrary axis coincide with the x axis and then we rotate

	glm::mat4 MT1 = tr1 * rot_y * rot_z * rot_x * rot_z_inv * rot_y_inv * tr1_inv;
			   
	//reverse order of matrix operation since we have matrix on the left convention
	// p' = T(px, py, pz ) ? Ry (? ) ? Rz (? ) ? Rx (? ) ? Rz (? )?1 ? Ry (? )?1 ?T(px, py, pz )?1 ? p





	// Half the size of an object, using as fixed point (5,0,-2)

	glm::mat4 tr2 = glm::translate(glm::mat4(1), glm::vec3(5, 0, -2)); //T(1, 0, -1) Back
	glm::mat4 tr2_inv = inverse(tr2);

	glm::mat4 scl = glm::scale(glm::mat4(1), glm::vec3(0.5, 0.5, 0.5));

	glm::mat4 MT2 = tr2 * scl * tr2_inv;
			   




	// Mirror the starship along a plane passing through (1,1,1), and obtained rotating 15 degree around the x axis the xz plane

	glm::mat4 tr3 = glm::translate(glm::mat4(1), glm::vec3(1, 1, 1));
	glm::mat4 tr3_inv = inverse(tr3);

	glm::mat4 ro3_x = glm::rotate(glm::mat4(1), glm::radians(15.0f), glm::vec3(1, 0, 0));
	glm::mat4 rot3_inv = inverse(ro3_x);

	glm::mat4 scl3 = glm::scale(glm::mat4(1), glm::vec3(1, -1 , 1));
	
	glm::mat4 MT3 = tr3 * ro3_x * scl3 * rot3_inv * tr3_inv;

	//planar mirroring, I assing -1 to the scaling factor of the axis perpendicular to the plane, in this case Y=-1





	// Apply the inverse of the following sequence of transforms: Translation of (0, 0, 5) then rotation of 30 degree around the Y axis, and finally a uniform scaling of a factor of 3.
	
	glm::mat4 tr4 = glm::translate(glm::mat4(1), glm::vec3(0, 0, 5));
	glm::mat4 ro4_y = glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(0, 1, 0));
	glm::mat4 scl4 = glm::scale(glm::mat4(1), glm::vec3(3, 3, 3));
	

	glm::mat4 tr4_inv = inverse(tr4);
	glm::mat4 ro4_y_inv = inverse(ro4_y);
	glm::mat4 scl4_inv = inverse(scl4);

	glm::mat4 MT4 =  tr4_inv * ro4_y_inv * scl4_inv;
	 
	//Recall that the inverse of the product of two matrices, is the
	//product of the inverse matrices in the opposite order :

