package ru.mikheev.water;

import androidx.appcompat.app.AppCompatActivity;

import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        GLSurfaceView gLView = new GLSurfaceView(this);
        gLView.setBackgroundResource(R.drawable.water);
        gLView.setZOrderOnTop(true);
        gLView.setRenderer(new MyRenderer());
        setContentView(gLView);
    }
}