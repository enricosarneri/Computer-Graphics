	// Translate of +2 on the x axis, and -1 on the y axis
	const float MT1[] =  {
			   1.0,		0.0,		0.0,		2.0,
			   0.0,		1.0,		0.0,		-1.0,
			   0.0,		0.0,		1.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};
			   
	//Translation matrix the column on the right is the represents me the shifting of the translation

	//  1 0 0 dx
	//	0 1 0 dy
	//	0 0 1 dz
	//	0 0 0 1





	// Rotate of 45 degrees on the x axis
	const float MT2[] =  {
			   1.0,		0.0,		0.0,		0.0,
			   0.0,		float(1/sqrt(2)),		float(-1/sqrt(2)),		0.0,
			   0.0,		float(1/sqrt(2)),		float(1/sqrt(2)),		0.0,
			   0.0,		0.0,		0.0,		1.0};
			   
	//formula of the rotation matrix around y-axis

	// 1 0 0 0
	// 0 cosA ?sinA 0
	// 0 sinA cosA 0
	// 0 0 0 1
	//il sen o cos di 45 gradi è 1/sqrt(2)





	// Make the object 2 times smaller
	const float MT3[] =  {
			   0.5,		0.0,		0.0,		0.0,
			   0.0,		0.5,		0.0,		0.0,
			   0.0,		0.0,		0.5,		0.0,
			   0.0,		0.0,		0.0,		1.0};
			

	//Scaling Matrix: the s factor is halved
	//  sx 0 0 0
	//	0 sy 0 0
	//	0 0 sz 0
	//	0 0 0 1







	// Make the object 2 times longer on the z axis, and half on the other axis
	const float MT4[] =  {
			   0.5,		0.0,		0.0,		0.0,
			   0.0,		0.5,		0.0,		0.0,
			   0.0,		0.0,		2.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};

	//Scaling Matrix
	//  sx 0 0 0
	//	0 sy 0 0
	//	0 0 sz 0
	//	0 0 0 1






	// Mirror over the z axis
	const float MT5[] =  {
			   -1.0,		0.0,		0.0,		0.0,
			   0.0,		-1.0,		0.0,		0.0,
			   0.0,		0.0,		1.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};
			
	//Axial Mirroring: I put minus to the scaling factor of the other dimensions w.r.t the one 
	//I want to mirror to

	//Scaling Matrix
	//  sx 0 0 0
	//	0 sy 0 0
	//	0 0 sz 0
	//	0 0 0 1






	// Flatten over the z axis
	const float MT6[] =  {
			   1.0,		0.0,		0.0,		0.0,
			   0.0,		1.0,		0.0,		0.0,
			   0.0,		0.0,		0.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};

	//I just put 0 the scaling factor of the dimension i want to flatten
	//Scaling Matrix
	//  sx 0 0 0
	//	0 sy 0 0
	//	0 0 sz 0
	//	0 0 0 1






	// Make a shear along the Y axis, with a factor of 1 along the x axis
	const float MT7[] =  {
			   1.0,		1.0,		0.0,		0.0,
			   0.0,		1.0,		0.0,		0.0,
			   0.0,		0.0,		1.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};
	//Shear Matrix w.r.t Y axis
	//  1 hx 0 0
	//	0 1 0 0
	//	0 hz 1 0
	//	0 0 0 1

	//-> hz = 0 (don't specified) -> hx=1