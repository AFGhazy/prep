package com.afghazy.mvvm.models

enum class Token {
    X, O;
    companion object {
        fun getToken(value: Int): Token {
            values().forEachIndexed {
                idx, token -> if(idx == value) return token
            }
            return X
        }
    }
}