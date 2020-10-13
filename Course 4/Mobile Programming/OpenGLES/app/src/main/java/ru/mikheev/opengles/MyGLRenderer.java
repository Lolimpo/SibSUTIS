package ru.mikheev.opengles;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.opengl.GLU;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class MyGLRenderer implements GLSurfaceView.Renderer {
    Context context;

    private Square mSquare;
    private Cube mCube;
    private Sphere mSphere;

    private static float angleCube = 0;
    private static float speedCube = -1.5f;

    private float mTransY = 0f;
    private float mAngle = 0;

    public MyGLRenderer(Context context) {
        this.context = context;
        mSquare = new Square();
        mCube = new Cube();
        mSphere = new Sphere(5);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        gl.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        gl.glClearDepthf(1.0f);
        gl.glEnable(GL10.GL_DEPTH_TEST);
        gl.glDepthFunc(GL10.GL_LEQUAL);
        gl.glHint(GL10.GL_PERSPECTIVE_CORRECTION_HINT, GL10.GL_NICEST);
        gl.glShadeModel(GL10.GL_SMOOTH);
        gl.glDisable(GL10.GL_DITHER);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        if (height == 0) height = 1;
        float aspect = (float)width / height;

        gl.glViewport(0, 0, width, height);

        gl.glMatrixMode(GL10.GL_PROJECTION);
        gl.glLoadIdentity();

        GLU.gluPerspective(gl, 45, aspect, 0.1f, 100.f);

        gl.glMatrixMode(GL10.GL_MODELVIEW);  // Select model-view matrix
        gl.glLoadIdentity();
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);

        gl.glLoadIdentity();
        gl.glTranslatef(-3f, 0.0f, -6.0f);
        mSquare.draw(gl);

        gl.glLoadIdentity();
        gl.glTranslatef(0.0f,(float)Math.sin(mTransY), -4.0f);
        gl.glScalef(0.2f, 0.2f, 0.2f);
        gl.glRotatef(mAngle, 1, 0, 0);
        mSphere.draw(gl);

        gl.glLoadIdentity();
        gl.glTranslatef(3f, 0.0f, -6.0f);
        gl.glScalef(0.8f, 0.8f, 0.8f);
        gl.glRotatef(angleCube, 1.0f, 1.0f, 1.0f);
        mCube.draw(gl);

        angleCube += speedCube;
        mTransY+=.0f;
        mAngle+=1.8;
    }

}
