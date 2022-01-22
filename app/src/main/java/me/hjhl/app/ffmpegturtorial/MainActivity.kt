package me.hjhl.app.ffmpegturtorial

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView

class MainActivity : AppCompatActivity() {

    companion object {
        private const val TAG = "MainActivity"
        private const val FFMPEG_LIBRARY = "ffmpeg"

        init {
            try {
                System.loadLibrary(FFMPEG_LIBRARY)
                Log.i(TAG, "load ffmpeg library success")
            } catch (e: Exception) {
                Log.d(TAG, e.message, e)
            }
        }
    }

    private lateinit var textView: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        textView = findViewById<TextView>(R.id.textView)
        initView()
    }

    private fun initView() {
        textView.apply {
            text = getFFMpegVersion()
        }
    }

    private external fun getFFMpegVersion(): String
}