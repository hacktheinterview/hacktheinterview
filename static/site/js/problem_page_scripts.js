$(document).ready(function() {
    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/twilight");
    editor.getSession().setMode("ace/mode/java");
    editor.setShowPrintMargin(false);
    editor.getSession().setUseWrapMode(true);
    editor.getSession().setUseWorker(false);
    document.getElementById('editor').style.fontSize = '15px';

    $("#default_compilation_status_area").hide();
    // var notes_editor = ace.edit("notes-editor");
    // notes_editor.setTheme("ace/theme/solarized_light");
    // notes_editor.getSession().setMode("ace/mode/text");
    // notes_editor.setShowPrintMargin(false);
    // notes_editor.getSession().setUseWrapMode(true);
    // notes_editor.renderer.setShowGutter(false);
    // notes_editor.renderer.setOption('showLineNumbers', false);
    // notes_editor.getSession().setUseWorker(false);
    // document.getElementById('notes_editor').style.fontSize = '13px';

});

$("#compile_and_test").click(function() {

    var editor = ace.edit("editor");
    var source_code = editor.getValue();
    var language_id = $("#selected-language").data("selected-lang-id");
    debugger;
    var problem_id = window.location.href.split("/")[4];
    var post_data = {
        "source_code": source_code,
        "language_id": language_id,
        "problem_id": problem_id,
        "isSample": false,
    };
    // Show submission status area
    $("#default_compilation_status_area").show();
    $("#submission_status_area").html("");
    console.log(post_data);
    $.post("/create_submission/", post_data, function(result_data) {
        submission_id = result_data.submission_id;
        var interval = setInterval(function(){poll_submission()}, 1500);
        function poll_submission() {
            console.log("polling... ");
            $.get("/get_submission_status/", {'submission_id' : submission_id}, function(submission_status){
                console.log(submission_status);
                $("#default_compilation_status_area").hide();
                if (submission_status["status"] != "QE") {
                    clearInterval(interval);
                }
                $("#submission_status_area").html(submission_status.htmlContent);
            });
        }
    });
});


$(".language-select-menu-item").on("click", function() {
    var selText = $(this).text();
    $(this).parents('.btn-group').find('#selected-language').html(selText+' <span class="caret"></span>');
    var problem_id = window.location.href.split("/")[4];
    var language_id = $(this).data("langid");
    $('#selected-language').data('selected-lang-id', language_id);
    $.get("/get_recent_submission/",
            {'language_id' : language_id, 'problem_id': problem_id},
            function(recentSubmission) {
                // TODO(Rad), add retry to jquery if server fails
        var editor = ace.edit("editor");
        editor.getSession().setValue(recentSubmission["source"]);
    });

});

$("#twilight").click(function(e) {
    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/twilight");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});

$("#monokai").click(function(e) {
    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/monokai");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});

$("#chrome").click(function(e) {
    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/chrome");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});

$("#xcode").click(function(e) {
    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/xcode");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});

$("#crimson_editor").click(function(e) {
    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/crimson_editor");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});
