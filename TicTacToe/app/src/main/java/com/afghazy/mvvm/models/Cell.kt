package com.afghazy.mvvm.models

data class Cell(val token: Token?) {
    fun isEmpty() = token == null
}