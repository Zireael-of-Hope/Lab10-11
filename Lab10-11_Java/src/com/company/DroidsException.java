package com.company;

public class DroidsException extends Exception {
    private String warning;
    DroidsException(String warning_message) {
        warning = warning_message;
    }

    public String what() {
        return warning;
    }
}