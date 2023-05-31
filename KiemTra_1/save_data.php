<?php
// Lấy dữ liệu từ form và tính toán các giá trị cần thiết
$name = $_POST['name'];
$month = $_POST['month'];
$year = $_POST['year'];
$startReading = $_POST['start_reading'];
$endReading = $_POST['end_reading'];
$consumption = $endReading - $startReading;

$unitPrice = 0;
if ($consumption <= 10) {
    $unitPrice = $consumption * 5000;
} elseif ($consumption <= 20) {
    $unitPrice = (10 * 5000) + (($consumption - 10) * 10000);
} elseif ($consumption <= 30) {
    $unitPrice = (10 * 5000) + (10 * 10000) + (($consumption - 20) * 15000);
} else {
    $unitPrice = (10 * 5000) + (10 * 10000) + (10 * 15000) + (($consumption - 30) * 20000);
}

$vat = $unitPrice * 0.1;
$bvmt = $unitPrice * 0.15;
$total = $unitPrice + $vat + $bvmt;

// Lưu thông tin vào file water.txt
$data = "$name\t$month\t$year\t$consumption\t$unitPrice\t$vat\t$bvmt\t$total\n";
file_put_contents('water.txt', $data, FILE_APPEND);

// Redirect về trang chủ
header('Location: ThongTin.php');
exit();
?>