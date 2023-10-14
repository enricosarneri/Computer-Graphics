#define GLM_FORCE_DEPTH_ZERO_TO_ONE //This directive, before including the library, forces the z - axis of the normalized screen coordinates in the zero - one range.

//PARALLEL PROJECTIONS

//The main parallel projection uses a half-width of w=2, the aspect ratio passed in parameter a
// and has the near and far planes located respectively at a distance of n=-4 and f=12.


glm::mat4 vk_ortho(float a)
{
	float w = 2;
	float l = -w;
	float r = w;
	float b = -w / a;
	float t = w / a;
	float n = -4;
	float f = 12;

	//l = ?w
	//r = w
	//t = w/a	
	//b = ?w/a
	//a= aspect ratio: The proportions of the physical screen

	//l, r, b, t, n, f are the positions in world
	//coordinates respectively of the left, right, bottom, top, near and
	//far boundaries of the visible region.


	// ortho() computes the orthographic projection matrix specifying the boundaries
	// plus some modifications to match vulkan conventions (y-axis flip)
	return glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) * glm::ortho(l, r, b, t, n, f); //This added matrix product flips the yaxis to match the Vulkan conventions.

}



// Create a matrix for Isometric projection with the given aspect ration a

glm::mat4 PO1(float a) {
	glm::mat4 rot45 = glm::rotate(glm::mat4(1),
		glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 rot35 = glm::rotate(glm::mat4(1),
		glm::radians(35.26f), glm::vec3(1.0f, 0.0f, 0.0f));

	return vk_ortho(a) * rot35 * rot45;
}
// Isometric projections are obtained by applying a rotation of ±45o around the y - axis, followed by a rotation of ±35.26o around the x - axis, before applying the parallel projection




// Create a matrix for Dimnetric projection (alpha = 45 degree)
// with the given aspect ration a
glm::mat4 PO2(float a)
{
	glm::mat4 rot1 = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rot2 = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	return vk_ortho(a) * rot2 * rot1;
}
// Dimetric projections are obtained by applying a rotation of ±45o around the y - axis, followed by an arbitrary rotation a around the x - axis, before applying the basic parallel projection.




// Create a matrix for Trimetric projection (alpha = 45 degree, beta = 60 degree)
// with the given aspect ration a
glm::mat4 PO3(float a)
{
	glm::mat4 rot1 = glm::rotate(glm::mat4(1), glm::radians(60.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rot2 = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	return vk_ortho(a) * rot2 * rot1;
}

//Trimetric projections are obtained by applying an arbitrary rotation b around the y - axis, followed by an arbitrary rotation a around the x - axis, before applying the parallel projection previously seen




// Create a matrix for Cabinet projection (alpha = 45) -> OBLIQUE PROJECTIONS, z-axis non parallel to the screen
// with the given aspect ration a
glm::mat4 PO4(float a)
{
	glm::mat4 shear = glm::mat4( //IMPORTANT!!!!! - THE ELEMENTS ARE PASSED BY COLUMN, not BY RAW!!!!!!!!!!!!!
		1, 0, 0, 0,
		0, 1, 0, 0,
		-0.5 * cos(45.0f), -0.5 * sin(45.0f), 1, 0,
		0, 0, 0, 1);
	return vk_ortho(a) * shear;
}

// Oblique projections can be obtained by applying a shear along the z - axis before the orthogonal projection.
//1 0 ?p(cosA)  0
//0 1 ?p(sinA)  0
//0 0 1 0
//0 0 0 1

//In particular, it can be expressed considering the angle a of the axis, and the corresponding reduction factor p.