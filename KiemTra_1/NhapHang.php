<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Nhập thông tin tiêu thụ</title>
    <script>
        function validateForm() {
            var name = document.forms["inputForm"]["name"].value;
            var month = document.forms["inputForm"]["month"].value;
            var year = document.forms["inputForm"]["year"].value;
            var startReading = document.forms["inputForm"]["start_reading"].value;
            var endReading = document.forms["inputForm"]["end_reading"].value;

            if (name == "" || month == "" || year == "" || startReading == "" || endReading == "") {
                alert("Vui lòng điền đầy đủ thông tin.");
                return false;
            }
        }
    </script>
</head>
<body>
    <form name="inputForm" action="save_data.php" method="post" onsubmit="return validateForm()">
        <table>
            <tr>
                <td>Họ và tên:</td>
                <td><input type="text" name="name"></td>
            </tr>
            <tr>
                <td>Tháng:</td>
                <td><input type="text" name="month"></td>
            </tr>
            </tr>
            <tr>
                <td>Năm:</td>
                <td><input type="text" name="year"></td>
            </tr>
            <tr>
                <td>Chỉ số đầu tháng:</td>
                <td><input type="text" name="start_reading"></td>
            </tr>
            <tr>
                <td>Chỉ số cuối tháng:</td>
                <td><input type="text" name="end_reading"></td>
            </tr>
            <tr>
                <td><button type="submit">Lưu</button></td>
            </tr>
        </table>
    </form>
</body>
</html>
