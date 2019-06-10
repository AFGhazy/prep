package com.afghazy.mvvm.views

import android.os.Bundle
import android.os.PersistableBundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.databinding.DataBindingUtil
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import com.afghazy.mvvm.R
import com.afghazy.mvvm.databinding.ActivityGameBinding
import com.afghazy.mvvm.viewmodels.GameViewModel


class GameActivity : AppCompatActivity() {
    private var gameViewModel: GameViewModel? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        val activityGameBinding: ActivityGameBinding = DataBindingUtil.setContentView(this, R.layout.activity_game)
        gameViewModel = ViewModelProviders.of(this).get(GameViewModel::class.java)
        activityGameBinding.gameViewModel = gameViewModel
        gameViewModel?.getWinner()?.observe(this, Observer {
            it?.name?.let {
                Toast.makeText(this, it, Toast.LENGTH_LONG).show()
            }
        })
        super.onCreate(savedInstanceState)
    }
}