概要

本プログラムはint型の入力があった時バッファーオーバーフローを起こさないような設計になっている。


テスト用メイン関数

int main() {
    int num = 0;
    num = get_input_int();
    printf("%d\n", num);
    return 0;
}