#define GLM_FORCE_DEPTH_ZERO_TO_ONE // This directive, before including the library, forces the z - axis of the normalized screen coordinates in the zero - one range

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 90o
glm::mat4 PO1(float a) {

	float n = 0.1;
	float f = 9.9;
	//FOVy = 90 
	// = the angle ? at the top of the frustum(known as “field of view” fov - y) over the y - axis


	//The perspective() function computes the perspective projection matrix specifying Fov and aspect ratio :
	glm::mat4 Port = glm::perspective(glm::radians(90.0f), a, n, f);

	//Since the Vulkan and OpenGL matrices for Fov / Aspect ratio projection
	//	differ only for the sign of the element in the second row / second column,
	//	in this special case it could be more convenient to just change the sign of
	//	this element instead of applying a mirroring transform.
	Port[1][1] *= -1;


	float l = -a * n * tan(90.0f/2);
	float r = a * n * tan(90.0f/2);
	float b = -n * tan(90.0f / 2);
	float t = n * tan(90.0f/2);

	glm::mat4 Port1 = glm::frustum(l, r, b, t, n, f);
	//Where l, r, b, t, n, f are the positions in world	coordinates respectively of the left, right, bottom, top, near and far boundaries of the visible region


	return Port;
}




// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 120o
glm::mat4 PO2(float a) {
	float n = 0.1;
	float f = 9.9;

	glm::mat4 Port = glm::perspective(glm::radians(120.0f), a, n, f);
	Port[1][1] *= -1;

	return Port;
}





// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 30o
glm::mat4 PO3(float a) {
	float n = 0.1;
	float f = 9.9;

	glm::mat4 Port = glm::perspective(glm::radians(30.0f), a, n, f);
	Port[1][1] *= -1;

	return Port;
}





// Create a matrix for Perspecrtive projection, with the given aspect ratio a.
// Here the perspective should only show the left side of the view
// with a FovY = 90o. Here r=0, and l, t and b should be computed
// to match both the aspect ratio and the FovY
glm::mat4 PO4(float a) {
	float n = 0.1;
	float f = 9.9;
	float r = 0.0;
	
	float l = -a * n * tan(glm::radians(90.0f / 2));
	float b = -n * tan(glm::radians(90.0f / 2));
	float t = n * tan(glm::radians(90.0f / 2));

	glm::mat4 Port1 = glm::frustum(l, r, b, t, n, f);
	//GLM provides the frustum() function to compute the perspective projection matrix specifying the boundaries


	return glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) * Port1;
	//This added matrix product flips the y - axis	to match the Vulkan conventions
}

