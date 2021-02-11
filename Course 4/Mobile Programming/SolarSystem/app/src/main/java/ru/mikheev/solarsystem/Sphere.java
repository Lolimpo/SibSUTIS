package ru.mikheev.solarsystem;

import android.opengl.GLSurfaceView;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

class Sphere implements GLSurfaceView.Renderer {
    private final FloatBuffer mVertexBuffer;
    public FloatBuffer textureBuffer;
    private int n = 0;

    private float[][] colors = {  // Colors of the 6 faces
            {1.0f, 0.0f, 1.0f, 1.0f},  // 0. orange
            {0.95f, 0.0f, 1.0f, 1.0f},  // 1. violet
            {0.9f, 0.0f, 1.0f, 1.0f},  // 1. violet
    };

    public Sphere(float R) {
        int dtheta = 15, dphi = 15;
        float DTOR = (float)(Math.PI / 180.0f);

        ByteBuffer byteBuf = ByteBuffer.allocateDirect(5000 * 3 * 4);
        byteBuf.order(ByteOrder.nativeOrder());
        mVertexBuffer = byteBuf.asFloatBuffer();
        byteBuf = ByteBuffer.allocateDirect(5000 * 2 * 4);
        byteBuf.order(ByteOrder.nativeOrder());
        textureBuffer = byteBuf.asFloatBuffer();

        for (int theta = -90; theta <= 90 - dtheta; theta += dtheta) {
            for (int phi = 0; phi <= 360 - dphi; phi += dphi){
                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.cos(phi*DTOR))*R);
                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.sin(phi*DTOR))*R);
                mVertexBuffer.put((float)(Math.sin(theta*DTOR))*R);

                mVertexBuffer.put((float)(Math.cos((theta+dtheta) * DTOR) * Math.cos(phi*DTOR))*R);
                mVertexBuffer.put((float)(Math.cos((theta+dtheta) * DTOR) * Math.sin(phi*DTOR))*R);
                mVertexBuffer.put((float)(Math.sin((theta+dtheta) * DTOR)) * R);

                mVertexBuffer.put((float)(Math.cos((theta+dtheta) * DTOR) * Math.cos((phi+dphi)*DTOR))*R);
                mVertexBuffer.put((float)(Math.cos((theta+dtheta) * DTOR) * Math.sin((phi+dphi)*DTOR))*R);
                mVertexBuffer.put((float)(Math.sin((theta+dtheta) * DTOR)) * R);
                n += 3;
                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.cos((phi+dphi)*DTOR))*R);
                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.sin((phi+dphi)*DTOR))*R);
                mVertexBuffer.put((float)(Math.sin(theta*DTOR))*R);
                n++;

                textureBuffer.put(phi / 360.0f);
                textureBuffer.put((90 + theta) / 180.0f);

                textureBuffer.put(phi / 360.0f);
                textureBuffer.put((90 + theta + dtheta) / 180.0f);

                textureBuffer.put((phi + dphi) / 360.0f);
                textureBuffer.put((90 + theta + dtheta) / 180.0f);

                textureBuffer.put((phi + dphi) / 360.0f);
                textureBuffer.put((90 + theta) / 180.0f);
            }
        }
        mVertexBuffer.position(0);
        textureBuffer.position(0);
    }
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        gl.glEnable(GL10.GL_BLEND);
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);

        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
        gl.glVertexPointer(3, GL10.GL_FLOAT, 0, mVertexBuffer);
        gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, textureBuffer);
        for (int i = 0; i < n; i += 4)
            gl.glDrawArrays(GL10.GL_TRIANGLE_FAN, i,4);

        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
        gl.glDisable(GL10.GL_BLEND);
    }
}
