package com.example.intent

import android.content.Intent
import android.net.Uri
import android.os.Build
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.activity.viewModels
import androidx.compose.foundation.layout.Column
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import coil.compose.AsyncImage
import com.example.intent.ui.theme.IntentTheme

class MainActivity : ComponentActivity() {

    private val photoViewModel by viewModels<PhotoViewModel>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            IntentTheme {
                Column {
//                    explicit intent
                    Button(onClick = {
                        Intent(applicationContext, SecondActivity::class.java).also {
                            startActivity(it)
                        }
                    }) {
                        Text(text = "new activity")
                    }
                    Button(onClick = {
                        Intent(Intent.ACTION_MAIN).also {
                            it.`package` = "com.google.android.youtube"
                            startActivity(it)
                        }
                    }) {
                        Text(text = "open youtube app")
                    }
//                    implicit intent
                    Button(onClick = {
                        val emailIntent = Intent(Intent.ACTION_SEND).apply {
                            type = "text/plain"
                            putExtra(Intent.EXTRA_EMAIL, arrayOf("test@test.com"))
                            putExtra(Intent.EXTRA_SUBJECT, "subject email")
                            putExtra(Intent.EXTRA_TEXT, "this is just some dummy text")
                        }
                        if(emailIntent.resolveActivity(packageManager) != null) {
                            startActivity(emailIntent)
                        }
                    }) {
                        Text(text = "Send dummy email")
                    }
//                    show image from another app, that send implicit intent
                    photoViewModel.imageUri?.let {
                        AsyncImage(
                            model = photoViewModel.imageUri,
                            contentDescription = null
                        )
                    }
                }
            }
        }
    }

    override fun onNewIntent(getIntent: Intent) {
        super.onNewIntent(getIntent)
        val uri = if(Build.VERSION.SDK_INT > Build.VERSION_CODES.TIRAMISU) {
            getIntent?.getParcelableExtra(Intent.EXTRA_STREAM, Uri::class.java)
        } else {
            getIntent?.getParcelableExtra(Intent.EXTRA_STREAM)
        }
        photoViewModel.updateImageUri(uri)
    }
}