/**************
 Function Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 Using function Triangle(...) try to draw a children house, similar to the one below.
 
 First remove the two function below (given only as an example), and replace them with your own.
 Since it is a C program, you can use for loops if you think it can be helpful in your drawing.
 The for() command below that draws a sun like shape in exact center of the screen near the top,
 is an example on how you can use it: please remove it, and replace it with your own code.
 It is not necessery to use a for loop if you do not really need it: it has been put here only as
 an example to help students not familiar with C++.
***************/


//Cielo
auto Square = [&](float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b) {
	Triangle(x1, y1, x2, y2, x3, y3, r, g, b);
	Triangle(x4, y4, x1, y1, x3, y3, r, g, b);
};

//Cielo
Square(1, 1, 1, -1, -1, -1, -1, 1, 0, 0.6, 1);


Triangle(0.36,-0.45, -0.03,0.17, 0.73,0.17,   1,0,0);// tetto rosso

Triangle(-1,0.82, 1,0.82, -1,1,   0,1,0); //prima parte del prato
Triangle(-1,1,   1,0.82,   1,1,    0,1,0);	// seconda parte del prato

Triangle(0.07,0.17,    0.64, 0.17,     0.64, 0.82,  0, 0, 1); // prima parte casa blu
Triangle(0.07, 0.17,    0.64, 0.82,     0.07, 0.82,     0, 0, 1); // seconda parte casa blu

Triangle(0.17, 0.27,    0.27, 0.27,    0.27, 0.41,   1, 1, 0); // prima parte finestra a sx
Triangle(0.17, 0.27,    0.17, 0.41,    0.27, 0.41,   1, 1, 0); //seconda parte finestra a sx

Triangle(0.54, 0.27,   0.44, 0.27,   0.54, 0.41,    1, 1, 0); // prima parte finestra a dx
Triangle(0.54, 0.41,   0.44, 0.27,    0.44, 0.41,   1, 1, 0); //seconda parte finestra a dx

Triangle(0.29, 0.5,      0.41, 0.5,       0.41, 0.82,   1, 1, 0); // prima parte porta
Triangle(0.29, 0.82,      0.29, 0.5,       0.41, 0.82,   1, 1, 0); //seconda parte porta



auto Sun = [&]() {
	float amplitude = 32;
	float offset2 = 0.06; //External Radius (of the disk)

	//0.02 offset Internal
	//0.10 offset External

	//radius
	for (int i = 0; i < 360; i++) {
		Triangle(0.65 + 0.02 * cos(6.28 / 32 * (i - 0.5)), -0.70 + 0.02 * sin(6.28 / 32 * (i - 0.5)),
			0.65 + 0.10 * cos(6.28 / 32 * i), -0.70 + 0.10 * sin(6.28 / 32 * i),
			0.65 + 0.02 * cos(6.28 / 32 * (i + 0.5)), -0.70 + 0.02 * sin(6.28 / 32 * (i + 0.5)),
			1, 1, 0);
	}
	
	//Filling 'Disk' part
	for (int i = 0; i < 360; i++) {
		Triangle(0.65, -0.70, //center coordinates
			0.65 + offset2 * cos(amplitude / 32 * i), -0.70 + offset2 * sin(amplitude / 32 * i),
			0.65 + offset2 * cos(amplitude / 32 * (i + 0.5)), -0.70 + offset2 * sin(amplitude / 32 * (i + 0.5)),
			1, 1, 0);
	}
};

Sun();

//Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)
//Normalized screen coordinates, (i.e. in range [-1,+1])
//The red, green and blue(r, g, b) values are in the range[0, 1].