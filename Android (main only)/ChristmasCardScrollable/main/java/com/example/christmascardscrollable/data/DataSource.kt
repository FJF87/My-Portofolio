package com.example.christmascardscrollable.data

import com.example.christmascardscrollable.R
import com.example.christmascardscrollable.model.Affirmation

class DataSource() {
    fun loadAffirmations(): List<Affirmation> {
        return listOf<Affirmation>(
            Affirmation(R.string.rudolf, R.drawable.rudolf),
            Affirmation(R.string.santa, R.drawable.santa),
            Affirmation(R.string.cookies, R.drawable.cookies),
            Affirmation(R.string.snowman, R.drawable.snowman),
            Affirmation(R.string.christmas_tree, R.drawable.christmas_tree),
            Affirmation(R.string.christmas_decoration, R.drawable.christmas_decoration)
        )
    }
}