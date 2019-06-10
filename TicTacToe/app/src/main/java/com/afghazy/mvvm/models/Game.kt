package com.afghazy.mvvm.models

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import java.util.*
import kotlin.collections.HashMap

data class Game(
    val players: List<Player> = List(PLAYERS_COUNT) { idx ->
        Player("P$idx", Token.getToken(idx))
    }
) {

    private lateinit var rows: HashMap<Token, Array<Int>>
    private lateinit var cols: HashMap<Token, Array<Int>>
    private lateinit var mDig: HashMap<Token, Int>
    private lateinit var aDig: HashMap<Token, Int>
    private lateinit var cells: MutableList<MutableList<Cell>>
    var winner: MutableLiveData<Player?> = MutableLiveData()

    init {
        reset()
    }

    var role: Int = 0
        get() = field % 2

    fun reset() {
        cells = getEmptyCellsTable()
        rows = getEmptyHash()
        cols = getEmptyHash()
        mDig = getEmptyHashDig()
        aDig = getEmptyHashDig()
        winner.value = null
        role = 0
    }

    fun gameStatus(): GameStatus {
        var sum = 0
        for(v in Token.values()) {
            for(i in 0 until BOARD_SIZE) {
                sum += rows[v]?.get(i) ?: 0
            }
        }
        if(sum == BOARD_SIZE * BOARD_SIZE) return GameStatus.DRAW

        if(winner.value == null) return GameStatus.IN_PROGRESS
        return GameStatus.THERE_IS_A_WINNER
    }

    fun checkMove(x: Int, y: Int) = cells[x][y].isEmpty() && gameStatus() == GameStatus.IN_PROGRESS

    fun updateCell(x: Int, y: Int) {
        if(cells[x][y].isEmpty() && gameStatus() == GameStatus.IN_PROGRESS) {
            val token = players[role].token
            cells[x][y] = Cell(token)

            rows[token]?.set(x, (rows[token]?.get(x)?: 0) + 1)
            cols[token]?.set(y, (cols[token]?.get(y)?: 0) + 1)
            if(x == y) { mDig.set(token, (mDig.get(token) ?: 0) + 1) }
            if(x == BOARD_SIZE - y - 1) { aDig.set(token, (aDig.get(token) ?: 0) + 1) }

            if(rows[token]?.get(x) == BOARD_SIZE
                || cols[token]?.get(y) == BOARD_SIZE
                || mDig[token] == BOARD_SIZE
                || aDig[token] == BOARD_SIZE) {
                winner.value = players[role]
            }

            role++
        }
    }

    companion object {
        const val PLAYERS_COUNT = 2
        const val BOARD_SIZE = 3

        fun getEmptyHash() = HashMap<Token, Array<Int>>().apply {
            for(token in Token.values())
                set(token, Array(BOARD_SIZE) { 0 })
        }

        fun getEmptyHashDig() = HashMap<Token, Int>().apply {
            for(token in Token.values())
                set(Token.X, 0)
        }

        fun getEmptyCellsTable() = MutableList(BOARD_SIZE) {
            MutableList<Cell>(BOARD_SIZE) { Cell(null) }
        }
    }
}