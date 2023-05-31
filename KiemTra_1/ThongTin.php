<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
        }
        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }
        .add-button {
            background-color: #2ecc71;
            color: white;
            border: none;
            padding: 10px 20px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin-bottom: 10px;
            cursor: pointer;
        }
    </style>
    <title>Thông tin tiêu thụ</title>
</head>
<body>
    <a href="NhapHang.php"><button class="add-button" type="button">Thêm</button></a>
    <table width="100%" border="1" style="border-collapse: collapse;">
        <tr>
            <th>STT</th>
            <th>Họ và tên</th>
            <th>Tháng</th>
            <th>Năm</th>
            <th>Số nước tiêu thụ</th>
            <th>Thành tiền</th>
            <th>Thuế VAT(10%)</th>
            <th>Thuế BVMT(15%)</th>
            <th>Tổng tiền</th>
        </tr>

        <?php
        $fh = fopen("water.txt", "r") or die("Can't open file!");
        $count = 0;
        while(!feof($fh)){
            $count ++;
            $line = fgets($fh);
            if($line != ""){
                $temp = explode("\t", $line);
            ?>
                <tr>
                    <td><?=$count?></td>
                    <td><?=$temp[0]?></td>
                    <td><?=$temp[1]?></td>
                    <td><?=$temp[2]?></td>
                    <td><?=$temp[3]?></td>
                    <td><?=$temp[4]?></td>
                    <td><?=$temp[5]?></td>
                    <td><?=$temp[6]?></td>
                    <td><?=$temp[7]?></td>
                </tr>
                <?php
                }
            }
        ?>
        </tr>
    </table>
</body>
</html>