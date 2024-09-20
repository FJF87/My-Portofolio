package com.example.composequadrant

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.composequadrant.ui.theme.ComposeQuadrantTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            ComposeQuadrantTheme {
                Surface {
                    QuadranApp()
                }
            }
        }
    }
}

@Composable
fun TextInformation(
    title: String,
    description: String,
    bgcolor: Color,
    modifier: Modifier = Modifier
) {
    Column(
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally,
        modifier = modifier
            .fillMaxSize()
            .background(bgcolor)
            .padding(16.dp)
    ) {
        Text(
            text = title,
            fontWeight = FontWeight.Bold
        )
        Text(
            text = description,
            textAlign = TextAlign.Justify
        )
    }
}

@Composable
fun QuadranApp() {
    Column(
//        Modifier.fillMaxSize()
    ) {
        Row(
            Modifier
//                .fillMaxSize()
                .weight(1f)
        ) {
            TextInformation(
                title = "Text composable",
                description = "Displays text and follows the recommended Material Design guidelines.",
                bgcolor = Color(0xFFEADDFF),
                modifier = Modifier.weight(1f)
            )
            TextInformation(
                title = "Image composable",
                description = "Creates a composable that lays out and draws a given Painter class object.",
                bgcolor = Color(0xFFD0BCFF),
                modifier = Modifier.weight(1f)
            )
        }
        Row(
            Modifier
//                .fillMaxSize()
                .weight(1f)
        ) {
            TextInformation(
                title = "Row composable",
                description = "A layout composable that places its children in a horizontal sequence.",
                bgcolor = Color(0xFFB69DF8),
                modifier = Modifier.weight(1f)
            )
            TextInformation(
                title = "Column composable",
                description = "A layout composable that places its children in a vertical sequence.",
                bgcolor = Color(0xFFF6EDFF),
                modifier = Modifier.weight(1f)
            )
        }
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    ComposeQuadrantTheme {
        QuadranApp()
    }
}