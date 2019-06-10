package com.afghazy.mvvm.viewmodels

import androidx.databinding.ObservableArrayMap
import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import com.afghazy.mvvm.models.Game
import com.afghazy.mvvm.models.GameStatus
import com.afghazy.mvvm.models.Player
import com.afghazy.mvvm.models.Token

data class GameViewModel(
    var game: Game = Game(),
    val cells: ObservableArrayMap<String, String> = ObservableArrayMap()
) : ViewModel() {
    fun onClickedCellAt(x: Int, y: Int) {
        if (game.checkMove(x, y)) {
            game.updateCell(x, y)

            cells.put(x.toString() + y.toString(), game.players[game.role].token.name)

            if (game.gameStatus() != GameStatus.IN_PROGRESS) {
                game.reset()
                for (i in 0 until Game.BOARD_SIZE) for (j in 0 until Game.BOARD_SIZE) cells[
                        i.toString() + j.toString()] = ""
            }
        }
    }

    fun getWinner(): LiveData<Player?> {
        return game.winner
    }
}