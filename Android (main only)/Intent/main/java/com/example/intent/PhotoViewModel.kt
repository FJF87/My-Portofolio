package com.example.intent

import android.net.Uri
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.lifecycle.ViewModel

class PhotoViewModel: ViewModel() {
    var imageUri: Uri? by mutableStateOf(null)
        private set

    fun updateImageUri(newUri: Uri?) {
        this.imageUri = newUri
    }
}