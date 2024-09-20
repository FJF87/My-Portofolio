package com.example.fileapi

import android.content.Context
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.TextField
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.fileapi.ui.theme.FileAPITheme
import java.io.File

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            FileAPITheme {
                FileBox(this)
            }
        }
    }
}

@Composable
fun FileBox(context: Context) {
    val file = File(context.filesDir,"example.txt")
    var inputText by remember {
        mutableStateOf("")
    }
    var getText by remember {
        mutableStateOf("")
    }

    Column(
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally,
        modifier = Modifier.fillMaxSize()
    ) {
        TextField(
            value = inputText,
            onValueChange = {inputText = it}
        )
        Text(text = inputText)
        Button(onClick = {
            try {
                file.writeText(inputText)
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }) {
            Text(text = "save text")
        }
        Spacer(modifier = Modifier.height(20.dp))
        Button(onClick = {
            try {
                getText = file.readText()
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }) {
            Text(text = "read text")
        }
        Text(text = "Text in the memory: $getText")
    }
}