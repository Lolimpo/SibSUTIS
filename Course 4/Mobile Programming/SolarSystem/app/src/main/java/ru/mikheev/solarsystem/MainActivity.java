package ru.mikheev.solarsystem;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class MainActivity extends Activity {

    private GLSurfaceView gLView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        gLView = new GLSurfaceView(this);
        gLView.setRenderer(new MyGLRenderer(this));
        gLView.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
        setContentView(gLView);
    }

    @Override
    protected void onPause() {
        super.onPause();
        gLView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        gLView.onResume();
    }
}