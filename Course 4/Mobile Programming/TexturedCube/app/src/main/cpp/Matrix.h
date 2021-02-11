//
// Created by Lolimpo on 01.12.2020.
//

#ifndef TEXTURED_CUBE_MATRIX_H
#define TEXTURED_CUBE_MATRIX_H

void matrixIdentityFunction(float* matrix);
void matrixTranslate(float* matrix, float x, float y, float z);
void matrixMultiply(float* destination, float* operand1, float* operand2);
void matrixFrustum(float* matrix, float left, float right, float bottom, float top, float zNear, float zFar);
void matrixPerspective(float* matrix, float fieldOfView, float aspectRatio, float zNear, float zFar);
void matrixRotateX(float* matrix, float angle);
void matrixRotateY(float* matrix, float angle);
void matrixRotateZ(float* matrix, float angle);
void matrixScale(float* matrix,float x, float y, float z);
float matrixDegreesToRadians(float degrees);

#endif //TEXTURED_CUBE_MATRIX_H
