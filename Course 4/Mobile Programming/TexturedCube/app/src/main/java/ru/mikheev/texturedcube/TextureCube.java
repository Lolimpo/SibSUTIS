package ru.mikheev.texturedcube;

import android.os.Bundle;
import android.app.Activity;
import android.util.Log;

public class TextureCube extends Activity
{
    private static String LOGTAG = "TextureCube";
    protected TutorialView graphicsView;
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        Log.i(LOGTAG, "Creating New Tutorial View");
        graphicsView = new TutorialView(getApplication());
        setContentView(graphicsView);
    }
    @Override protected void onPause()
    {
        super.onPause();
        graphicsView.onPause();
    }
    @Override protected void onResume()
    {
        super.onResume();
        graphicsView.onResume();
    }

}