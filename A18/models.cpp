// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

#define PI 3.14159265359

struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;

	Vertex() {
		pos = glm::vec3();
		norm = glm::vec3();
	}

	Vertex(glm::vec3 pos, glm::vec3 norm) {
		this->pos = pos;
		this->norm = norm;
	}
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;
std::vector<Vertex> M3_vertices;
std::vector<Vertex> M4_vertices;

auto map = [](double number, double in_min, double in_max, double out_min, double out_max)
{
	return (number - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
};

void makeModels() {
//// M1 : Cube
// Replace the code below, that creates a simple square, with the one to create a cube.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices
	M1_vertices.resize(3*8);
	//x orizz dx, y vert up, z verso di noi


	// first vertex of M1  (0)
	Vertex v0x = Vertex(); //back bot l
	v0x.pos = glm::vec3(-1.0, -1.0, -1.0);
	v0x.norm = glm::vec3(-1.0, 0.0, 0.0);

	Vertex v0y = Vertex();
	v0y.pos = glm::vec3(-1.0, -1.0, -1.0);
	v0y.norm = glm::vec3(0.0, -1.0, 0.0);

	Vertex v0z = Vertex();
	v0z.pos = glm::vec3(-1.0, -1.0, -1.0);
	v0z.norm = glm::vec3(0.0, 0.0, -1.0);

	// second vertex of M1 (1)
	Vertex v1x = Vertex(); 
	v1x.pos = glm::vec3(-1.0, -1.0, 1.0);
	v1x.norm = glm::vec3(-1.0, 0.0, 0.0);

	Vertex v1y = Vertex();
	v1y.pos = glm::vec3(-1.0, -1.0, 1.0);
	v1y.norm = glm::vec3(0.0, -1.0, 0.0);

	Vertex v1z = Vertex();
	v1z.pos = glm::vec3(-1.0, -1.0, 1.0);
	v1z.norm = glm::vec3(0.0, 0.0, 1.0);


	// third vertex of M1 (2)
	Vertex v2x = Vertex();
	v2x.pos = glm::vec3(-1.0, 1.0, 1.0);
	v2x.norm = glm::vec3(-1.0, 0.0, 0.0);

	Vertex v2y = Vertex();
	v2y.pos = glm::vec3(-1.0, 1.0, 1.0);
	v2y.norm = glm::vec3(0.0, 1.0, 0.0);

	Vertex v2z = Vertex();
	v2z.pos = glm::vec3(-1.0, 1.0, 1.0);
	v2z.norm = glm::vec3(0.0, 0.0, 1.0);


	// fourth vertex of M1 (3)
	Vertex v3x = Vertex();
	v3x.pos = glm::vec3(-1.0, 1.0, -1.0);
	v3x.norm = glm::vec3(-1.0, 0.0, 0.0);

	Vertex v3y = Vertex();
	v3y.pos = glm::vec3(-1.0, 1.0, -1.0);
	v3y.norm = glm::vec3(0.0, 1.0, 0.0);

	Vertex v3z = Vertex();
	v3z.pos = glm::vec3(-1.0, 1.0, -1.0);
	v3z.norm = glm::vec3(0.0, 0.0, -1.0);


	// five vertex of M1 (4)
	Vertex v4x = Vertex();
	v4x.pos = glm::vec3(1.0, -1.0, -1.0);
	v4x.norm = glm::vec3(1.0, 0.0, 0.0);

	Vertex v4y = Vertex();
	v4y.pos = glm::vec3(1.0, -1.0, -1.0);
	v4y.norm = glm::vec3(0.0, -1.0, 0.0);

	Vertex v4z = Vertex();
	v4z.pos = glm::vec3(1.0, -1.0, -1.0);
	v4z.norm = glm::vec3(0.0, 0.0, -1.0);


	// sixth vertex of M1 (5)
	Vertex v5x = Vertex();
	v5x.pos = glm::vec3(1.0, -1.0, 1.0);
	v5x.norm = glm::vec3(1.0, 0.0, 0.0);

	Vertex v5y = Vertex();
	v5y.pos = glm::vec3(1.0, -1.0, 1.0);
	v5y.norm = glm::vec3(0.0, -1.0, 0.0);

	Vertex v5z = Vertex();
	v5z.pos = glm::vec3(1.0, -1.0, 1.0);
	v5z.norm = glm::vec3(0.0, 0.0, 1.0);



	//// seventh vertex of M1 (6)
	Vertex v6x = Vertex();
	v6x.pos = glm::vec3(1.0, 1.0, 1.0);
	v6x.norm = glm::vec3(1.0, 0.0, 0.0);

	Vertex v6y = Vertex();
	v6y.pos = glm::vec3(1.0, 1.0, 1.0);
	v6y.norm = glm::vec3(0.0, 1.0, 0.0);

	Vertex v6z = Vertex();
	v6z.pos = glm::vec3(1.0, 1.0, 1.0);
	v6z.norm = glm::vec3(0.0, 0.0, 1.0);


	//// eight vertex of M1 (7)
	Vertex v7x = Vertex();
	v7x.pos = glm::vec3(1.0, 1.0, -1.0);
	v7x.norm = glm::vec3(1.0, 0.0, 0.0);

	Vertex v7y = Vertex();
	v7y.pos = glm::vec3(1.0, 1.0, -1.0);
	v7y.norm = glm::vec3(0.0, 1.0, 0.0);

	Vertex v7z = Vertex();
	v7z.pos = glm::vec3(1.0, 1.0, -1.0);
	v7z.norm = glm::vec3(0.0, 0.0, -1.0);

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



	/*
		left side
	
			2---------- 3
			-		 -
			-		 -
			-		 -
			1---------- 0

	
	*/

	M1_indices = {
		0,3,6, //left side
		6,9,0, //left side

		(0 * 3) + 2, (3 * 3) + 2, (4 * 3) + 2, //back face
		(4 * 3) + 2,  (3 * 3) + 2,  (7 * 3) + 2, //back face

		(5 * 3), (6 * 3), (7 * 3), //right side
		(7 * 3), (4 * 3), (5 * 3), //right side

		(1 * 3) + 2, (6 * 3) + 2, (5 * 3) + 2,	//front face
		(1 * 3) + 2, (2 * 3) + 2, (6 * 3) + 2, //front face
	
		(7 * 3) + 1 ,  (6 * 3) + 1,  (2 * 3) + 1, //top face
		(3 * 3) + 1, (2 * 3) + 1, (7 * 3) + 1, //top face

		(4 * 3) + 1, (5 * 3) + 1, (0 * 3) + 1, //bottom face
		(1 * 3) + 1, (0 * 3) + 1, (5 * 3) + 1 //bottom face
	};







//// M2 : Cylinder
// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.
// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices		

	int N = 8;//numero slices
	double radius = 1;
	double height = 2;

	M2_vertices.resize((N * 2 + 1) * 2);

	M2_vertices[0].pos = glm::vec3(0.0, 0.0, 0.0);		// bottom cap center
	M2_vertices[0].norm = glm::vec3(0.0, -1.0, 0.0);

	M2_vertices[1].pos = glm::vec3(0.0, height, 0.0);	// top cap center
	M2_vertices[1].norm = glm::vec3(0.0, 1.0, 0.0);


	double angleStep = (2 * PI) / N;

	for (int i = 0; i < N; i++) {
		int vertexIndex = (i + 1) * 2;

		double x = radius * std::cos(angleStep * i);
		double z = radius * std::sin(angleStep * i);

		// bottom ring

		//bottom cap ring
		M2_vertices[vertexIndex].pos = glm::vec3(x, 0.0, z);
		M2_vertices[vertexIndex].norm = glm::vec3(0.0, -1.0, 0.0);//normale verso il basso

		//bottom side ring
		M2_vertices[vertexIndex + 1].pos = glm::vec3(x, 0.0, z);
		M2_vertices[vertexIndex + 1].norm = glm::vec3(x, 0.0, z); //normale segue x e z


		// top ring

		vertexIndex += N * 2;

		//top cap ring
		M2_vertices[vertexIndex].pos = glm::vec3(x, height, z);
		M2_vertices[vertexIndex].norm = glm::vec3(0.0, 1.0, 0.0); //normale verso l'alto

		//top side ring
		M2_vertices[vertexIndex + 1].pos = glm::vec3(x, height, z);
		M2_vertices[vertexIndex + 1].norm = glm::vec3(x, 0.0, z); //normale segue x e z
	}





	M2_indices.resize(N * 2 * 2 * 3); // N*2 per i triangoli dei 2 cerchi + N*2 per i triangoli di lati (2 per faccia) (tot = numero triangoli *3)

	for (int i = 0; i < N; i++) {

		// bottom cap

		int indexStartIndex = 3 * i;

		M2_indices[indexStartIndex] = 0;
		M2_indices[indexStartIndex + 1] = i * 2 + 2;
		M2_indices[indexStartIndex + 2] = i == N - 1 ? 2 : i * 2 + 4; //salta di uno perché quello in mezzo è il vertice corrispondente per per il laterale


		// top cap

		indexStartIndex += N * 3; //parto da N*3 perché gli indici prima mi sono occupati dal bottom circle

		M2_indices[indexStartIndex] = 1;
		M2_indices[indexStartIndex + 1] = (i + N) * 2 + 2; //si parte da n*2 + 2 perché i top vertices partono da N*2
		M2_indices[indexStartIndex + 2] = i == N - 1 ? N * 2 + 2 : (i + N) * 2 + 4;


		// Lati
		int bottomVertex = i * 2 + 3;
		int topVertex = bottomVertex + N * 2;

		int index = N * 2 * 3 + i * 6; //si parte da N*6 perché prima ho due volte N*3 e ogni round che occupo 6 quindi i+6

		//2 in basso + 1 in alto
		M2_indices[index] = bottomVertex;
		M2_indices[index + 1] = bottomVertex == N * 2 + 1 ? 3 : bottomVertex + 2;
		M2_indices[index + 2] = bottomVertex == N * 2 + 1 ? N * 2 + 3 : topVertex + 2;

		//2 in alto + 1 in basso
		M2_indices[index + 3] = topVertex;
		M2_indices[index + 4] = bottomVertex == N * 2 + 1 ? N * 2 + 3 : topVertex + 2;
		M2_indices[index + 5] = bottomVertex;

	}







	//// M3 : Sphere
	// Replace the code below, that creates a simple triangle, with the one to create a sphere.

	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices

	N = 44; // vertici per circonferenza
	radius = 1;
	
	M3_vertices.resize((N + 1) * (N + 1));

	for (int i = 0; i <= N; i++) {

		double lon = (i * (PI * 2) / N) + PI; // Map 0 -> N to -PI -> PI //stack angle mi indica gli slice orizzontali

		for (int j = 0; j <= N; j++) {

			double lat = ((j * PI) / N) - (PI / 2); // Map 0 -> N to -PI/2 -> PI/2 //sector angle mi indica gli slice verticali

			int vertexIndex = (i * (N + 1)) + j;

			double x = radius * std::sin(lon) * std::cos(lat);
			double y = radius * std::sin(lon) * std::sin(lat);
			double z = radius * std::cos(lon);

			M3_vertices[vertexIndex].pos = glm::vec3(x, y, z);
			M3_vertices[vertexIndex].norm = glm::vec3(x, y, z); //each vertex share both the position and the normal vector direction.

		} //http://www.songho.ca/opengl/gl_sphere.html

	}


	// Resizes the indices array. Repalce the values with the correct number of
	// indices (3 * number of triangles)

									//tolgo primo e ultimo slice
	M3_indices.resize(((N * N * 2) - (N * 2)) * 3);


	int k = 0;

	for (int i = 0; i < N; i++) {

		int col = i * (N + 1);
		int nextCol = col + N + 1;

		for (int j = 0; j < N; j++) {

			if (i != 0)
			{
				M3_indices[k++] = col;
				M3_indices[k++] = col + 1;
				M3_indices[k++] = nextCol;
			}

			if (i != (N - 1))
			{
				M3_indices[k++] = nextCol;
				M3_indices[k++] = nextCol + 1;
				M3_indices[k++] = col + 1;
			}

			col++;
			nextCol++;
		}


	}








}