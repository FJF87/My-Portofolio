package com.example.christmascardscrollable

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.WindowInsets
import androidx.compose.foundation.layout.asPaddingValues
import androidx.compose.foundation.layout.calculateEndPadding
import androidx.compose.foundation.layout.calculateStartPadding
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.safeDrawing
import androidx.compose.foundation.layout.statusBarsPadding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalLayoutDirection
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.LayoutDirection
import androidx.compose.ui.unit.dp
import com.example.christmascardscrollable.data.DataSource
import com.example.christmascardscrollable.model.Affirmation
import com.example.christmascardscrollable.ui.theme.ChristmasCardScrollableTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            Surface(
                modifier = Modifier.fillMaxSize(),
                color = MaterialTheme.colorScheme.background
            ) {
                ChristmasCardApp()
            }
        }
    }
}

@Composable
fun ChristmasCard(affirmation: Affirmation, modifier: Modifier = Modifier) {
    Column(
        verticalArrangement = Arrangement.Center,
        modifier = modifier.fillMaxWidth()
    ) {
        Image(
            painter = painterResource(id = affirmation.imageResourceId),
            contentDescription = stringResource(id = affirmation.stringResourceId)
        )
        Text(
            text = stringResource(id = affirmation.stringResourceId),
            textAlign = TextAlign.Center
        )
    }
}

@Composable
fun ChristmasCardList(listOfAffirmation: List<Affirmation>, modifier: Modifier = Modifier) {
    LazyColumn(
        modifier = modifier.verticalScroll(rememberScrollState())
    ) {
        items(listOfAffirmation) { affirmation ->
            ChristmasCard(
                affirmation = affirmation,
                modifier = modifier.padding(10.dp)
            )
        }
    }
}

@Composable
fun ChristmasCardApp(modifier: Modifier = Modifier) {
    val layoutDirection = LocalLayoutDirection.current
    Surface(
        modifier = modifier
            .fillMaxSize()
            .statusBarsPadding()
            .padding(
                start = WindowInsets.safeDrawing
                    .asPaddingValues()
                    .calculateStartPadding(layoutDirection),
                end = WindowInsets.safeDrawing
                    .asPaddingValues()
                    .calculateEndPadding(layoutDirection)
            )
    ) {
        ChristmasCardList(
            listOfAffirmation = DataSource().loadAffirmations()
        )
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    ChristmasCardScrollableTheme {
        ChristmasCardApp()
    }
}