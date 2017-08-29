package com.yqq.ndkstudy;

/**
 * Created by Administrator on 2017/8/24 0024.
 */

public class User {
    public String getmName() {
        return mName;
    }

    public void setmName(String mName) {
        this.mName = mName;
    }

    public String mName;
    public String mAge;

    @Override
    public String toString() {
        return "User{" +
                "mName='" + mName + '\'' +
                ", mAge='" + mAge + '\'' +
                '}';
    }
}
