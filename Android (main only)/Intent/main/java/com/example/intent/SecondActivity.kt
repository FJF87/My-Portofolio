package com.example.intent

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.material3.Text

class SecondActivity: ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
//        receive extra from another intent
//        intent.getStringExtra()
        setContent {
            Text(text = "second activity")
        }
    }
}