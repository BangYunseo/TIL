package com.yunseo_33.ch08_event

import android.os.Bundle
import android.view.MotionEvent
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import android.util.Log
import android.view.KeyEvent

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }
    override fun onKeyDown(keyCode: Int, event: KeyEvent?): Boolean{
        when(keyCode){
            KeyEvent.KEYCODE_0 -> Log.d("Yunseo", "0 키가 눌림")
            KeyEvent.KEYCODE_A -> Log.d("Yunseo", "A 키가 눌림")
        }
        return super.onKeyDown(keyCode, event)
    }
}