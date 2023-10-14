// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
#define M_PI 3.14159265359
 
struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
	glm::vec2 UV;


	Vertex() {
		pos = glm::vec3();
		norm = glm::vec3();
		UV = glm::vec2();
	}

	Vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 UV) {
		this->pos = pos;
		this->norm = norm;
		this->UV = UV;
	}
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;


void makeModels() {
	//// M1 : Cube
	// Replace the code below, that creates a simple square, with the one to create a cube.

	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices
	M1_vertices.resize(3 * 8);
	//x orizz dx, y vert up, z verso di noi


	// first vertex of M1  (0)
	Vertex v0x = Vertex(); //back bot l
	v0x.pos = glm::vec3(-1.0, -1.0, -1.0);
	v0x.norm = glm::vec3(-1.0, 0.0, 0.0);
	v0x.UV = glm::vec2(0.125, 0.375);

	Vertex v0y = Vertex();
	v0y.pos = glm::vec3(-1.0, -1.0, -1.0);
	v0y.norm = glm::vec3(0.0, -1.0, 0.0);
	v0y.UV = glm::vec2(0.125, 0.375);


	Vertex v0z = Vertex();
	v0z.pos = glm::vec3(-1.0, -1.0, -1.0);
	v0z.norm = glm::vec3(0.0, 0.0, -1.0);
	v0z.UV = glm::vec2(0.125, 0.375);

	// second vertex of M1 (1)
	Vertex v1x = Vertex();
	v1x.pos = glm::vec3(-1.0, -1.0, 1.0);
	v1x.norm = glm::vec3(-1.0, 0.0, 0.0);
	v1x.UV = glm::vec2(0.0, 0.375);


	Vertex v1y = Vertex();
	v1y.pos = glm::vec3(-1.0, -1.0, 1.0);
	v1y.norm = glm::vec3(0.0, -1.0, 0.0);
	v1y.UV = glm::vec2(0.125, 0.5);

	Vertex v1z = Vertex();
	v1z.pos = glm::vec3(-1.0, -1.0, 1.0);
	v1z.norm = glm::vec3(0.0, 0.0, 1.0);
	v1z.UV = glm::vec2(0.125, 0.0);


	// third vertex of M1 (2)
	Vertex v2x = Vertex();
	v2x.pos = glm::vec3(-1.0, 1.0, 1.0);
	v2x.norm = glm::vec3(-1.0, 0.0, 0.0);
	v2x.UV = glm::vec2(0.0, 0.25);


	Vertex v2y = Vertex();
	v2y.pos = glm::vec3(-1.0, 1.0, 1.0);
	v2y.norm = glm::vec3(0.0, 1.0, 0.0);
	v2y.UV = glm::vec2(0.125, 0.125);

	Vertex v2z = Vertex();
	v2z.pos = glm::vec3(-1.0, 1.0, 1.0);
	v2z.norm = glm::vec3(0.0, 0.0, 1.0);
	v2z.UV = glm::vec2(0.125, 0.125);


	// fourth vertex of M1 (3)
	Vertex v3x = Vertex();
	v3x.pos = glm::vec3(-1.0, 1.0, -1.0);
	v3x.norm = glm::vec3(-1.0, 0.0, 0.0);
	v3x.UV = glm::vec2(0.125, 0.25);


	Vertex v3y = Vertex();
	v3y.pos = glm::vec3(-1.0, 1.0, -1.0);
	v3y.norm = glm::vec3(0.0, 1.0, 0.0);
	v3y.UV = glm::vec2(0.125, 0.25);

	Vertex v3z = Vertex();
	v3z.pos = glm::vec3(-1.0, 1.0, -1.0);
	v3z.norm = glm::vec3(0.0, 0.0, -1.0);
	v3z.UV = glm::vec2(0.125, 0.25);


	// five vertex of M1 (4)
	Vertex v4x = Vertex();
	v4x.pos = glm::vec3(1.0, -1.0, -1.0);
	v4x.norm = glm::vec3(1.0, 0.0, 0.0);
	v4x.UV = glm::vec2(0.25, 0.375);


	Vertex v4y = Vertex();
	v4y.pos = glm::vec3(1.0, -1.0, -1.0);
	v4y.norm = glm::vec3(0.0, -1.0, 0.0);
	v4y.UV = glm::vec2(0.25, 0.375);


	Vertex v4z = Vertex();
	v4z.pos = glm::vec3(1.0, -1.0, -1.0);
	v4z.norm = glm::vec3(0.0, 0.0, -1.0);
	v4z.UV = glm::vec2(0.25, 0.375);


	// sixth vertex of M1 (5)
	Vertex v5x = Vertex();
	v5x.pos = glm::vec3(1.0, -1.0, 1.0);
	v5x.norm = glm::vec3(1.0, 0.0, 0.0);
	v5x.UV = glm::vec2(0.375, 0.375);


	Vertex v5y = Vertex();
	v5y.pos = glm::vec3(1.0, -1.0, 1.0);
	v5y.norm = glm::vec3(0.0, -1.0, 0.0);
	v5y.UV = glm::vec2(0.25, 0.5);

	Vertex v5z = Vertex();
	v5z.pos = glm::vec3(1.0, -1.0, 1.0);
	v5z.norm = glm::vec3(0.0, 0.0, 1.0);
	v5z.UV = glm::vec2(0.25, 0.0);



	//// seventh vertex of M1 (6)
	Vertex v6x = Vertex();
	v6x.pos = glm::vec3(1.0, 1.0, 1.0);
	v6x.norm = glm::vec3(1.0, 0.0, 0.0);
	v6x.UV = glm::vec2(0.375, 0.25);

	Vertex v6y = Vertex();
	v6y.pos = glm::vec3(1.0, 1.0, 1.0);
	v6y.norm = glm::vec3(0.0, 1.0, 0.0);
	v6y.UV = glm::vec2(0.25, 0.125);

	Vertex v6z = Vertex();
	v6z.pos = glm::vec3(1.0, 1.0, 1.0);
	v6z.norm = glm::vec3(0.0, 0.0, 1.0);
	v6z.UV = glm::vec2(0.25, 0.125);


	//// eight vertex of M1 (7)
	Vertex v7x = Vertex();
	v7x.pos = glm::vec3(1.0, 1.0, -1.0);
	v7x.norm = glm::vec3(1.0, 0.0, 0.0);
	v7x.UV = glm::vec2(0.25, 0.25);

	Vertex v7y = Vertex();
	v7y.pos = glm::vec3(1.0, 1.0, -1.0);
	v7y.norm = glm::vec3(0.0, 1.0, 0.0);
	v7y.UV = glm::vec2(0.25, 0.25);

	Vertex v7z = Vertex();
	v7z.pos = glm::vec3(1.0, 1.0, -1.0);
	v7z.norm = glm::vec3(0.0, 0.0, -1.0);
	v7z.UV = glm::vec2(0.25, 0.25);

	M1_vertices = {
		//front and back
		v0x,
		v0y,
		v0z,
		v1x,
		v1y,
		v1z,
		v2x,
		v2y,
		v2z,
		v3x,
		v3y,
		v3z,
		v4x,
		v4y,
		v4z,
		v5x,
		v5y,
		v5z,
		v6x,
		v6y,
		v6z,
		v7x,
		v7y,
		v7z
	};


	// Resizes the indices array. Repalce the values with the correct number of
	// indices (3 * number of triangles)
	M1_indices.resize(3 * 12);

	M1_indices = {
		0,3,6,
		6,9,0,

		(0 * 3) + 2, (3 * 3) + 2, (4 * 3) + 2,
		(4 * 3) + 2,  (3 * 3) + 2,  (7 * 3) + 2,

		(5 * 3), (6 * 3), (7 * 3),
		(7 * 3), (4 * 3), (5 * 3),

		(1 * 3) + 2, (6 * 3) + 2, (5 * 3) + 2,
		(1 * 3) + 2, (2 * 3) + 2, (6 * 3) + 2,

		(7 * 3) + 1 ,  (6 * 3) + 1,  (2 * 3) + 1,
		(3 * 3) + 1, (2 * 3) + 1, (7 * 3) + 1,

		(4 * 3) + 1, (5 * 3) + 1, (0 * 3) + 1,
		(1 * 3) + 1, (0 * 3) + 1, (5 * 3) + 1
	};

	//// M2 : Cylinder
	// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices
	int NSlices = 72;
	float xc = 0.0f;
	float yc = 0.0f;
	float zc = 0.0f;
	float r = 1.0f;
	float height = 2;
	float ruv = 0.125f; //radius of the texture

	M2_vertices.resize(2 * (2 * (NSlices + 1) + 6));

	//Vertices definition

	//top cap center
	M2_vertices[0].pos = glm::vec3(xc, yc + height, zc);
	M2_vertices[0].norm = glm::vec3(0.0f, 1.0f, 0.0f);
	M2_vertices[0].UV = glm::vec2(0.625, 0.125);
	float uincr = (1 - 0.5) / NSlices;


	for (int i = 1; i < NSlices + 1; i++) {
		//top ring
		M2_vertices[2 * i - 1].pos = glm::vec3(xc + r * cos(2 * M_PI / NSlices * i), yc + height, zc + r * sin(2 * M_PI / NSlices * i));
		M2_vertices[2 * i - 1].norm = glm::vec3(0.0f, 1.0f, 0.0f);
		M2_vertices[2 * i - 1].UV = glm::vec2(0.625 + ruv * cos(2 * M_PI / NSlices * i), 0.125 + ruv * sin(2 * M_PI / NSlices * i));

		//top side
		M2_vertices[2 * i + 0].pos = glm::vec3(xc + r * cos(2 * M_PI / NSlices * i), yc + height, zc + r * sin(2 * M_PI / NSlices * i));
		M2_vertices[2 * i + 0].norm = glm::vec3(cos(2 * M_PI / NSlices * i), 0.0f, sin(2 * M_PI / NSlices * i));
		M2_vertices[2 * i + 0].UV = glm::vec2(1 - (i * uincr), 0.25f);
	}

	M2_vertices[2 * (NSlices + 1) - 1].pos = glm::vec3(xc + r * cos(2 * M_PI), yc + height, zc + r * sin(2 * M_PI));
	M2_vertices[2 * (NSlices + 1) - 1].norm = glm::vec3(0.0f, 1.0f, 0.0f);
	M2_vertices[2 * (NSlices + 1) - 1].UV = glm::vec2(0.625 + ruv * cos(2 * M_PI), 0.125 + ruv * sin(2 * M_PI));

	M2_vertices[2 * (NSlices + 1) + 0].pos = glm::vec3(xc + r * cos(2 * M_PI), yc + height, zc + r * sin(2 * M_PI));
	M2_vertices[2 * (NSlices + 1) + 0].norm = glm::vec3(cos(2 * M_PI), 0.0f, sin(2 * M_PI));
	M2_vertices[2 * (NSlices + 1) + 0].UV = glm::vec2(1.0f, 0.25f);

	int offset = 2 * (NSlices + 1) + 1;

	//bottom cap center
	M2_vertices[offset].pos = glm::vec3(xc, yc, zc);
	M2_vertices[offset].norm = glm::vec3(0.0f, -1.0f, 0.0f);
	M2_vertices[offset].UV = glm::vec2(0.875, 0.125);

	for (int i = 1; i < NSlices + 1; i++) {
		//bottom ring
		M2_vertices[2 * i - 1 + offset].pos = glm::vec3(xc + r * cos(2 * M_PI / NSlices * i), yc, zc + r * sin(2 * M_PI / NSlices * i));
		M2_vertices[2 * i - 1 + offset].norm = glm::vec3(0.0f, -1.0f, 0.0f);
		M2_vertices[2 * i - 1 + offset].UV = glm::vec2(0.875 + ruv * cos(2 * M_PI / NSlices * i), 0.125 + ruv * sin(2 * M_PI / NSlices * i));

		//bottom side
		M2_vertices[2 * i + 0 + offset].pos = glm::vec3(xc + r * cos(2 * M_PI / NSlices * i), yc, zc + r * sin(2 * M_PI / NSlices * i));
		M2_vertices[2 * i + 0 + offset].norm = glm::vec3(cos(2 * M_PI / NSlices * i), 0.0f, sin(2 * M_PI / NSlices * i));
		M2_vertices[2 * i + 0 + offset].UV = glm::vec2(1 - (i * uincr), 0.5f);
	}

	M2_vertices[2 * (NSlices + 1) - 1 + offset].pos = glm::vec3(xc + r * cos(2 * M_PI), yc, zc + r * sin(2 * M_PI));
	M2_vertices[2 * (NSlices + 1) - 1 + offset].norm = glm::vec3(0.0f, -1.0f, 0.0f);
	M2_vertices[2 * (NSlices + 1) - 1 + offset].UV = glm::vec2(0.875 + ruv * cos(2 * M_PI), 0.125 + ruv * sin(2 * M_PI));

	M2_vertices[2 * (NSlices + 1) + 0 + offset].pos = glm::vec3(xc + r * cos(2 * M_PI), yc, zc + r * sin(2 * M_PI));
	M2_vertices[2 * (NSlices + 1) + 0 + offset].norm = glm::vec3(cos(2 * M_PI), 0.0f, sin(2 * M_PI));
	M2_vertices[2 * (NSlices + 1) + 0 + offset].UV = glm::vec2(1.0f, 0.5f);


	// Resizes the indices array. Repalce the values with the correct number of
	// indices (3 * number of triangles)
	M2_indices.resize(3 * ((NSlices + 1) * 2 + 2 * (NSlices + 1)));

	// indices definitions
	for (int i = 0; i < NSlices; i++) {
		M2_indices[3 * i + 0] = 0;
		M2_indices[3 * i + 1] = 2 * i + 1;
		M2_indices[3 * i + 2] = 2 * (i + 1) + 1;
	}
	M2_indices[3 * (NSlices)+0] = 0;
	M2_indices[3 * (NSlices)+1] = 2 * (NSlices + 1) - 1;
	M2_indices[3 * (NSlices)+2] = 1;

	int i_offset = 3 * (NSlices);

	for (int i = 1; i < NSlices + 1; i++) {
		M2_indices[3 * i + 0 + i_offset] = 2 * i + offset;
		M2_indices[3 * i + 1 + i_offset] = 2 * i;
		M2_indices[3 * i + 2 + i_offset] = 2 * (i + 1);
	}

	M2_indices[3 * (NSlices + 1) + 0 + i_offset] = 2 * (NSlices + 1) + offset;
	M2_indices[3 * (NSlices + 1) + 1 + i_offset] = 2 * (NSlices + 1);
	M2_indices[3 * (NSlices + 1) + 2 + i_offset] = 2;

	i_offset += 3 * (NSlices)+3;

	for (int i = 1; i < NSlices + 1; i++) {
		M2_indices[3 * i + 0 + i_offset] = 2 * i + offset;
		M2_indices[3 * i + 1 + i_offset] = 2 * (i + 1);
		M2_indices[3 * i + 2 + i_offset] = 2 * (i + 1) + offset;
	}

	M2_indices[3 * (NSlices + 1) + 0 + i_offset] = 2 * (NSlices + 1) + offset;
	M2_indices[3 * (NSlices + 1) + 1 + i_offset] = 2;
	M2_indices[3 * (NSlices + 1) + 2 + i_offset] = offset + 2;


	i_offset += 3 * (NSlices + 1) + 3;

	for (int i = 0; i < NSlices; i++) {
		M2_indices[3 * i + 0 + i_offset] = offset + 0;
		M2_indices[3 * i + 1 + i_offset] = offset + 2 * i + 1;
		M2_indices[3 * i + 2 + i_offset] = offset + 2 * (i + 1) + 1;
	}

	M2_indices[3 * (NSlices)+0 + i_offset] = offset + 0;
	M2_indices[3 * (NSlices)+1 + i_offset] = offset + 2 * (NSlices + 1) - 1;
	M2_indices[3 * (NSlices)+2 + i_offset] = offset + 1;

}


