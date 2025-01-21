<?php
if (isset($_POST['image'])) {
    $data = $_POST['image'];

    $data = str_replace('data:image/png;base64,', '', $data);
    $data = str_replace(' ', '+', $data);
    $data = base64_decode($data);

    $file = '../../server/smb_' . uniqid() . '.png';

    if (file_put_contents($file, $data)) {
        echo "error" . $file;
    } else {
        echo "error";
    }
} else {
    echo "error";
}
?>
