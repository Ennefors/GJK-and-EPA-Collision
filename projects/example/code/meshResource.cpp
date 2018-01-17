#include "config.h"
#include "string.h"
#include "MeshResource.h"



MeshResource *MeshResource::createCube() 
	{
	MeshResource *mesh = new MeshResource;

	mesh->vertBuffer = new vertex[8];
	mesh->intBuffer = new int[36];

	mesh->vertBufSize = 8;
	mesh->intBufSize = 36;

	vertex vert0;
	vertex vert1;
	vertex vert2;
	vertex vert3;	
	vertex vert4;
	vertex vert5;
	vertex vert6;
	vertex vert7;

	vert0.pos.set_Vector(-0.5f, -0.5f, 0.5f);
	vert1.pos.set_Vector(0.5f, -0.5, 0.5f);
	vert2.pos.set_Vector(0.5f, 0.5f, 0.5f);
	vert3.pos.set_Vector(-0.5f, 0.5f, 0.5f);

	vert4.pos.set_Vector(-0.5f, -0.5f, -0.5f);
	vert5.pos.set_Vector(0.5f, -0.5, -0.5f);
	vert6.pos.set_Vector(0.5f, 0.5f, -0.5f);
	vert7.pos.set_Vector(-0.5f, 0.5f, -0.5f);

	fdVector uv1(0, 0, 0, 0);
	fdVector uv2(0, 1, 1, 1);
	fdVector uv3(1, 0, 0, 1);
	fdVector uv4(1, 1, 1, 1);


	vert0.uv = uv2;
	vert1.uv = uv1;
	vert2.uv = uv3;
	vert3.uv = uv4;

	vert4.uv = uv4;
	vert5.uv = uv3;
	vert6.uv = uv1;
	vert7.uv = uv2;

	mesh->vertBuffer[0] = vert0;
	mesh->vertBuffer[1] = vert1;
	mesh->vertBuffer[2] = vert2;
	mesh->vertBuffer[3] = vert3;
	mesh->vertBuffer[4] = vert4;
	mesh->vertBuffer[5] = vert5;
	mesh->vertBuffer[6] = vert6;
	mesh->vertBuffer[7] = vert7;

	mesh->intBuffer[0] = 2;
	mesh->intBuffer[1] = 1;
	mesh->intBuffer[2] = 0;

	mesh->intBuffer[3] = 0;
	mesh->intBuffer[4] = 3;
	mesh->intBuffer[5] = 2;



	mesh->intBuffer[6] = 5;
	mesh->intBuffer[7] = 4;
	mesh->intBuffer[8] = 0;

	mesh->intBuffer[9] = 0;
	mesh->intBuffer[10] = 1;
	mesh->intBuffer[11] = 5;



	mesh->intBuffer[12] = 6;
	mesh->intBuffer[13] = 5;
	mesh->intBuffer[14] = 1;

	mesh->intBuffer[15] = 1;
	mesh->intBuffer[16] = 2;
	mesh->intBuffer[17] = 6;



	mesh->intBuffer[18] = 7;
	mesh->intBuffer[19] = 6;
	mesh->intBuffer[20] = 2;

	mesh->intBuffer[21] = 2;
	mesh->intBuffer[22] = 3;
	mesh->intBuffer[23] = 7;



	mesh->intBuffer[24] = 0;
	mesh->intBuffer[25] = 4;
	mesh->intBuffer[26] = 7;

	mesh->intBuffer[27] = 7;
	mesh->intBuffer[28] = 3;
	mesh->intBuffer[29] = 0;



	mesh->intBuffer[30] = 4;
	mesh->intBuffer[31] = 5;
	mesh->intBuffer[32] = 7;

	mesh->intBuffer[33] = 7;
	mesh->intBuffer[34] = 5;
	mesh->intBuffer[35] = 6;

	mesh->setUp(mesh->vertBufSize, mesh->vertBuffer, mesh->intBufSize, mesh->intBuffer);
	return mesh;
}

MeshResource* MeshResource::loadObj(char* path)
{
	MeshResource *objMesh = new MeshResource;
	bool hasnorm = true;
	bool hasuvs = true;
	

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;

	std::vector<fdVector> temp_verticePos;
	std::vector<fdVector> temp_normals;
	std::vector<fdVector> temp_uvs;

	FILE* file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open file!\n");
		return false;
	}

	while (1) {
		char lineHeader[128];
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break;

		if (strcmp(lineHeader, "v") == 0)
		{
			float f[3];
			fdVector poss;
			fscanf(file, "%f %f %f\n", &f[0], &f[1], &f[2]);
			poss.set_Vector(f[0], f[1], f[2]);
			temp_verticePos.push_back(poss);

		}
		else if (strcmp(lineHeader, "vt") == 0)
		{
			float f[2];
			fdVector uv;
			fscanf(file, "%f %f\n", &f[0], &f[1]);
			uv.set_X(f[0]);
			uv.set_Y(f[1]);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0)
		{
			float f[3];
			fdVector norm;
			fscanf(file, "%f %f %f\n", &f[0], &f[1], &f[2]);
			norm.set_Vector(f[0], f[1], f[2]);
			temp_normals.push_back(norm);
		}
		else if (strcmp(lineHeader, "f") == 0)
		{
			if (temp_normals.size() == 0)
				hasnorm = false;

			if (temp_uvs.size() == 0)
				hasuvs = false;

			unsigned int vertIndex[4], uvIndex[4], normIndex[4];
			int match;

			if (hasnorm && !hasuvs)
			{
				match = fscanf(file, " %d%*[/]%d %d%*[/]%d %d%*[/]%d %d%*[/]%d\n", &vertIndex[0], &normIndex[0],
							   &vertIndex[1],  &normIndex[1],
							   &vertIndex[2], &normIndex[2],
							   &vertIndex[3], &normIndex[3]);
			}

			else if (!hasnorm && hasuvs)
			{
				match = fscanf(file, " %d%*[/]%d%*[/] %d%*[/]%d%*[/] %d%*[/]%d%*[/] %d%*[/]%d%*[/]\n", &vertIndex[0], &uvIndex[0],
							   &vertIndex[1], &uvIndex[1],
							   &vertIndex[2], &uvIndex[2],
							   &vertIndex[3], &uvIndex[3]);
			}
			else if (hasnorm && hasuvs)
			{
				match = fscanf(file, "%d%*[/]%d%*[/]%d %d%*[/]%d%*[/]%d %d%*[/]%d%*[/]%d %d%*[/]%d%*[/]%d\n",
							   &vertIndex[0], &uvIndex[0], &normIndex[0], &vertIndex[1], &uvIndex[1], &normIndex[1],
							   &vertIndex[2], &uvIndex[2], &normIndex[2], &vertIndex[3], &uvIndex[3],
							   &normIndex[3]);
			} else
			{
				match = fscanf(file, "%d %d %d %d\n", &vertIndex[0], &vertIndex[1], &vertIndex[2], &vertIndex[3]);
			}

			if (match == 12) {
				vertexIndices.push_back(vertIndex[0]);
				vertexIndices.push_back(vertIndex[1]);
				vertexIndices.push_back(vertIndex[2]);
				vertexIndices.push_back(vertIndex[3]);

				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
				uvIndices.push_back(uvIndex[3]);

				normalIndices.push_back(normIndex[0]);
				normalIndices.push_back(normIndex[1]);
				normalIndices.push_back(normIndex[2]);
				normalIndices.push_back(normIndex[3]);
			}
			else if (match == 9){
				vertexIndices.push_back(vertIndex[0]);
				vertexIndices.push_back(vertIndex[1]);
				vertexIndices.push_back(vertIndex[2]);

				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);

				normalIndices.push_back(normIndex[0]);
				normalIndices.push_back(normIndex[1]);
				normalIndices.push_back(normIndex[2]);
			}
			else if (match == 8) {
				vertexIndices.push_back(vertIndex[0]);
				vertexIndices.push_back(vertIndex[1]);
				vertexIndices.push_back(vertIndex[2]);
				vertexIndices.push_back(vertIndex[3]);
				if (hasnorm) {
					normalIndices.push_back(normIndex[0]);
					normalIndices.push_back(normIndex[1]);
					normalIndices.push_back(normIndex[2]);
					normalIndices.push_back(normIndex[3]);
				}
				if (hasuvs) {
					uvIndices.push_back(uvIndex[0]);
					uvIndices.push_back(uvIndex[1]);
					uvIndices.push_back(uvIndex[2]);
					uvIndices.push_back(uvIndex[3]);

				}
			}
			else if (match == 6) {
				vertexIndices.push_back(vertIndex[0]);
				vertexIndices.push_back(vertIndex[1]);
				vertexIndices.push_back(vertIndex[2]);

				if (hasnorm) {
					normalIndices.push_back(normIndex[0]);
					normalIndices.push_back(normIndex[1]);
					normalIndices.push_back(normIndex[2]);
				}
				if (hasuvs) {
					uvIndices.push_back(uvIndex[0]);
					uvIndices.push_back(uvIndex[1]);
					uvIndices.push_back(uvIndex[2]);
				}
			}
			else if (match == 4) {
				vertexIndices.push_back(vertIndex[0]);
				vertexIndices.push_back(vertIndex[1]);
				vertexIndices.push_back(vertIndex[2]);
				vertexIndices.push_back(vertIndex[3]);
			}
			else if (match == 3) {
				vertexIndices.push_back(vertIndex[0]);
				vertexIndices.push_back(vertIndex[1]);
				vertexIndices.push_back(vertIndex[2]);
			}
			
		}
	}

	objMesh->vertBuffer = new vertex[vertexIndices.size()];
	objMesh->intBuffer = new int[vertexIndices.size()];

	objMesh->intBufSize = vertexIndices.size();
	objMesh->vertBufSize = temp_verticePos.size();

	for (unsigned int i = 0; i < vertexIndices.size(); i++) {
		objMesh->intBuffer[i] = vertexIndices[i] - 1;

        vertex t;
        t.pos.set_Vector(temp_verticePos[vertexIndices[i] - 1].get_X(), temp_verticePos[vertexIndices[i] - 1].get_Y(), temp_verticePos[vertexIndices[i] - 1].get_Z());

		if (i == 0)
		{
			objMesh->boundsMax = t.pos;
		}

        if (i == 0)
        {
            objMesh->boundsMin = t.pos;
        }

		if(objMesh->boundsMax.get_X() < t.pos.get_X())
			objMesh->boundsMax.set_X(t.pos.get_X());
		if(objMesh->boundsMax.get_Y() < t.pos.get_Y())
			objMesh->boundsMax.set_Y(t.pos.get_Y());
		if(objMesh->boundsMax.get_Z() < t.pos.get_Z())
			objMesh->boundsMax.set_Z(t.pos.get_Z());

        if(objMesh->boundsMin.get_X() > t.pos.get_X())
            objMesh->boundsMin.set_X(t.pos.get_X());
        if(objMesh->boundsMin.get_Y() > t.pos.get_Y())
            objMesh->boundsMin.set_Y(t.pos.get_Y());
        if(objMesh->boundsMin.get_Z() > t.pos.get_Z())
            objMesh->boundsMin.set_Z(t.pos.get_Z());

        if (hasuvs) {
            int uvind = uvIndices[i] - 1;
            t.uv.set_Vector(temp_uvs[uvind].get_X(), temp_uvs[uvind].get_Y(), temp_uvs[uvind].get_Z());


        }
        if (hasnorm) {
            int nind = normalIndices[i] - 1;
            t.norm.set_Vector(temp_normals[nind].get_X(), temp_normals[nind].get_Y(), temp_normals[nind].get_Z());
        }
        objMesh->vertBuffer[i] = t;
	}

	objMesh->aabb.max = objMesh->boundsMax;
	objMesh->aabb.min = objMesh->boundsMin;

	fdVector insert;
	objMesh->OOBBbase.push_back(objMesh->boundsMin);
	insert.set_Vector(objMesh->boundsMin[0], objMesh->boundsMax[1], objMesh->boundsMin[2]);
	objMesh->OOBBbase.push_back(insert);
	insert.set_Vector(objMesh->boundsMax[0], objMesh->boundsMax[1], objMesh->boundsMin[2]);
	objMesh->OOBBbase.push_back(insert);
	insert.set_Vector(objMesh->boundsMax[0], objMesh->boundsMin[1], objMesh->boundsMin[2]);
	objMesh->OOBBbase.push_back(insert);

	objMesh->OOBBbase.push_back(objMesh->boundsMax);
	insert.set_Vector(objMesh->boundsMax[0], objMesh->boundsMin[1], objMesh->boundsMax[2]);
	objMesh->OOBBbase.push_back(insert);
	insert.set_Vector(objMesh->boundsMin[0], objMesh->boundsMin[1], objMesh->boundsMax[2]);
	objMesh->OOBBbase.push_back(insert);
	insert.set_Vector(objMesh->boundsMin[0], objMesh->boundsMax[1], objMesh->boundsMax[2]);
	objMesh->OOBBbase.push_back(insert);

	objMesh->OOBB.push_back(objMesh->boundsMin);
	insert.set_Vector(objMesh->boundsMin[0], objMesh->boundsMax[1], objMesh->boundsMin[2]);
	objMesh->OOBB.push_back(insert);
	insert.set_Vector(objMesh->boundsMax[0], objMesh->boundsMax[1], objMesh->boundsMin[2]);
	objMesh->OOBB.push_back(insert);
	insert.set_Vector(objMesh->boundsMax[0], objMesh->boundsMin[1], objMesh->boundsMin[2]);
	objMesh->OOBB.push_back(insert);

	objMesh->OOBB.push_back(objMesh->boundsMax);
	insert.set_Vector(objMesh->boundsMax[0], objMesh->boundsMin[1], objMesh->boundsMax[2]);
	objMesh->OOBB.push_back(insert);
	insert.set_Vector(objMesh->boundsMin[0], objMesh->boundsMin[1], objMesh->boundsMax[2]);
	objMesh->OOBB.push_back(insert);
	insert.set_Vector(objMesh->boundsMin[0], objMesh->boundsMax[1], objMesh->boundsMax[2]);
	objMesh->OOBB.push_back(insert);

	objMesh->setUp(objMesh->vertBufSize, objMesh->vertBuffer, objMesh->intBufSize, objMesh->intBuffer);
	return objMesh;

}

void MeshResource::setUp(int nrOfVertices, vertex* vertBuffer, int nrOfIndexes, int* intBuffer)
{
		
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * nrOfIndexes, vertBuffer, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

//		glGenBuffers(1, &ebo);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * nrOfIndexes, intBuffer, GL_STATIC_DRAW);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		indexCount = nrOfIndexes;
}

void MeshResource::draw()
	{
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float32) * 12, NULL);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float32) * 12, (GLvoid*)(sizeof(float32) * 4));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float32) * 12, (GLvoid*)(sizeof(float32) * 8));
	glDrawArrays(GL_TRIANGLES, 0, indexCount);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}

