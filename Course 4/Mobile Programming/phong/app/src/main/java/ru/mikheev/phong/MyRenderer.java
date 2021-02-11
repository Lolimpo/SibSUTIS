package ru.mikheev.phong;

import android.content.Context;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.opengl.Matrix;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class MyRenderer implements GLSurfaceView.Renderer {

    private Context context;
    private float xCamera, yCamera, zCamera;
    private float xLightPosition, yLightPosition, zLightPosition;
    private float[] modelMatrix;
    private float[] viewMatrix;
    private float[] modelViewMatrix;
    private float[] projectionMatrix;
    private float[] modelViewProjectionMatrix;
    private FloatBuffer vertexBuffer;
    private FloatBuffer normalBuffer;
    private FloatBuffer colorBuffer;
    private Shader mShader;

    public MyRenderer(Context context) {
        this.context = context;
        xLightPosition = 0f;
        yLightPosition = 0.5f;
        zLightPosition = 0f;
        modelMatrix = new float[16];
        viewMatrix = new float[16];
        modelViewMatrix = new float[16];
        projectionMatrix = new float[16];
        modelViewProjectionMatrix = new float[16];

        Matrix.setIdentityM(modelMatrix, 0);
        xCamera = 0f;
        yCamera = 8f;
        zCamera = 0.01f;

        Matrix.setLookAtM(
                viewMatrix, 0, xCamera, yCamera, zCamera, 0, 0, 0, 0, 2, 0);
        Matrix.multiplyMM(modelViewMatrix, 0, viewMatrix, 0, modelMatrix, 0);

        float x1 = -2;
        float y1 = 0;
        float z1 = -2;

        float x2 = -2;
        float y2 = 0;
        float z2 = 2;

        float x3 = 2;
        float y3 = 0;
        float z3 = -2;

        float x4 = 2;
        float y4 = 0;
        float z4 = 2;
        float[] vertexArray = {x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4};

        ByteBuffer bvertex = ByteBuffer.allocateDirect(vertexArray.length * 4);
        bvertex.order(ByteOrder.nativeOrder());
        vertexBuffer = bvertex.asFloatBuffer();
        vertexBuffer.position(0);

        vertexBuffer.put(vertexArray);
        vertexBuffer.position(0);

        float nx = 0;
        float ny = 1;
        float nz = 0;
        float[] normalArray = {nx, ny, nz,   nx, ny, nz,   nx, ny, nz,   nx, ny, nz};
        ByteBuffer bnormal = ByteBuffer.allocateDirect(normalArray.length*4);
        bnormal.order(ByteOrder.nativeOrder());
        normalBuffer = bnormal.asFloatBuffer();
        normalBuffer.position(0);
        normalBuffer.put(normalArray);
        normalBuffer.position(0);

        float[] colorArray = {
                0.5f, 0.5f, 0.5f, 1,
                0.5f, 0.5f, 0.5f, 1,
                0.5f, 0.5f, 0.5f, 1,
                0.5f, 0.5f, 0.5f, 1,
        };
        ByteBuffer bcolor = ByteBuffer.allocateDirect(colorArray.length * 4);
        bcolor.order(ByteOrder.nativeOrder());
        colorBuffer = bcolor.asFloatBuffer();
        colorBuffer.position(0);
        colorBuffer.put(colorArray);
        colorBuffer.position(0);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        GLES20.glEnable(GLES20.GL_DEPTH_TEST);
        GLES20.glEnable(GLES20.GL_CULL_FACE);
        GLES20.glHint(GLES20.GL_GENERATE_MIPMAP_HINT, GLES20.GL_NICEST);

        String vertexShaderCode=
                        "uniform mat4 u_modelViewProjectionMatrix;"+
                        "attribute vec3 a_vertex;"+
                        "attribute vec3 a_normal;"+
                        "attribute vec4 a_color;"+
                        "varying vec3 v_vertex;"+
                        "varying vec3 v_normal;"+
                        "varying vec4 v_color;"+
                        "void main() {"+
                            "v_vertex=a_vertex;"+
                            "vec3 n_normal=normalize(a_normal);"+
                            "v_normal=n_normal;"+
                            "v_color=a_color;"+
                            "gl_Position = u_modelViewProjectionMatrix * vec4(a_vertex,1.0);"+
                        "}";
        String fragmentShaderCode=
                        "precision mediump float;"+
                        "uniform vec3 u_camera;"+
                        "uniform vec3 u_lightPosition;"+
                        "varying vec3 v_vertex;"+
                        "varying vec3 v_normal;"+
                        "varying vec4 v_color;"+
                        "void main() {"+
                            "vec3 n_normal = normalize(v_normal);"+
                            "vec3 lightvector = normalize(u_lightPosition - v_vertex);"+
                            "vec3 lookvector = normalize(u_camera - v_vertex);"+
                            "float ambient = 0.4;"+
                            "float k_diffuse = 0.8;"+
                            "float k_specular = 0.6;"+
                            "float diffuse = k_diffuse * max(dot(n_normal, lightvector), 0.0);"+
                            "vec3 reflectvector = reflect(-lightvector, n_normal);"+
                            "float specular = k_specular * pow(max(dot(lookvector, reflectvector), 0.0), 40.0);"+
                            "vec4 one = vec4(1.0,1.0,1.0,1.0);"+
                            "vec4 lightColor = (ambient + diffuse + specular) * one;"+
                            "gl_FragColor = mix(lightColor, v_color, 0.5);"+
                        "}";

        mShader = new Shader(vertexShaderCode, fragmentShaderCode);
        mShader.linkVertexBuffer(vertexBuffer);
        mShader.linkNormalBuffer(normalBuffer);
        mShader.linkColorBuffer(colorBuffer);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        GLES20.glViewport(0, 0, width, height);
        float ratio = (float) width / height;
        float k = 0.055f;
        float left = -k * ratio;
        float right = k * ratio;
        float bottom = -k;
        float near = 0.1f;
        float far = 10.0f;
        Matrix.frustumM(projectionMatrix, 0, left, right, bottom, k, near, far);
        Matrix.multiplyMM(modelViewProjectionMatrix,
                0, projectionMatrix, 0, modelViewMatrix, 0);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT | GLES20.GL_DEPTH_BUFFER_BIT);
        mShader.linkModelViewProjectionMatrix(modelViewProjectionMatrix);
        mShader.linkCamera(xCamera, yCamera, zCamera);
        mShader.linkLightSource(xLightPosition, yLightPosition, zLightPosition);
        mShader.useProgram();
        GLES20.glDrawArrays(GLES20.GL_TRIANGLE_STRIP, 0, 4);
    }
}
