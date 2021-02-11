package ru.mikheev.solarsystem;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLSurfaceView;
import android.opengl.GLU;
import android.opengl.GLUtils;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;
import static java.lang.Math.cos;
import static java.lang.Math.sin;

class MyGLRenderer implements GLSurfaceView.Renderer {
    static public int[] texture_name = {
            R.drawable.watermelon,
            R.drawable.apple,
            R.drawable.lemon,
            R.drawable.orange
    };

    static public int[] textures = new int [texture_name.length];
    Context c;
    private final Sphere Sun = new Sphere(3f);
    private final Sphere Earth = new Sphere(1.5f);
    private final Sphere Moon = new Sphere(1.5f);
    private final Sphere Orange = new Sphere(1.5f);

    public MyGLRenderer(Context context) {
        c = context;
    }

    private void loadGLTexture(GL10 gl) {
        gl.glGenTextures(3, textures, 0);
        for (int i = 0; i < texture_name.length; ++i) {
            gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[i]);
            gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_LINEAR);
            InputStream is = c.getResources().openRawResource(texture_name[i]);
            Bitmap bitmap = BitmapFactory.decodeStream(is);
            GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bitmap, 0);
            bitmap.recycle();
        }
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        gl.glClearColor(0.0f, 0.0f, 0.0f,1.0f);
        gl.glClearDepthf(1.0f);
        gl.glEnable(GL10.GL_DEPTH_TEST);
        gl.glDepthFunc(GL10.GL_LEQUAL);
        gl.glMatrixMode(GL10.GL_PROJECTION);
        gl.glLoadIdentity();
        gl.glOrthof(-10,10, -10, 10, -10, 10);
        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();
        gl.glScalef(1, 0.8f, 1);
        loadGLTexture(gl);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
//        if (height == 0) height = 1;
//        float aspect = (float)width / height;
//
//        gl.glViewport(0, 0, width, height);
//
//        gl.glMatrixMode(GL10.GL_PROJECTION);
//        gl.glLoadIdentity();
//
//        GLU.gluPerspective(gl, 90, aspect, 0.1f, 0.5f);
//
//        gl.glMatrixMode(GL10.GL_MODELVIEW);  // Select model-view matrix
//        gl.glLoadIdentity();
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);

        gl.glEnable(GL10.GL_TEXTURE_2D);
        gl.glTranslatef(0f, 0f, 0.0f);
        gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[0]);
        gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
        gl.glTexCoordPointer(1, GL10.GL_FLOAT, 0, Sun.textureBuffer);
        gl.glPushMatrix();
        gl.glScalef(1.5f, 1.5f, 1.5f);
        Sun.onDrawFrame(gl);

        gl.glPopMatrix();
        gl.glPushMatrix();
        gl.glTranslatef(3f, -2f, 4.0f);
        gl.glScalef(1.5f, 1.5f, 1.5f);
        gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[1]);
        gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, Earth.textureBuffer);
        Earth.onDrawFrame(gl);

        gl.glPopMatrix();
        gl.glPushMatrix();
        gl.glTranslatef(-2f, -2.7f, 4.0f);
        gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[2]);
        gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, Moon.textureBuffer);
        gl.glColor4f(1, 1 ,1, 1);
        Moon.onDrawFrame(gl);

        gl.glPopMatrix();
        gl.glPushMatrix();
        gl.glTranslatef(-3.8f, -2.7f, 5f);
        gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[3]);
        gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, Orange.textureBuffer);
        gl.glColor4f(1, 1 ,1, 1);
        Orange.onDrawFrame(gl);

        gl.glPopMatrix();
        gl.glDisableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
        gl.glDisable(GL10.GL_TEXTURE_2D);
    }
}
