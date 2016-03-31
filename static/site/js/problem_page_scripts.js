$(document).ready(function() {
    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/twilight");
    editor.getSession().setMode("ace/mode/javascript");
    editor.setShowPrintMargin(false);
    editor.getSession().setUseWrapMode(true);
    editor.getSession().setUseWorker(false);
    document.getElementById('editor').style.fontSize = '15px';

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
    var language = 1;
    var source_code = editor.getValue();
    var problem_id = 1;

    // if(language === "C")
    //     source_code = c_editor.getValue();
    // else if(language === "CPP")
    //     source_code = cpp_editor.getValue();

    // $("#compile_and_test").attr("disabled", "disabled");
    // $("#loading_spinner").show();

    var post_data = {"source_code": source_code, "language": language, "problem_id": problem_id};

    $.post("/compile_and_test/", post_data, function(result_data) {
        var interval = setInterval(function(){poll_compilation()}, 1000);
        function poll_compilation() {
            console.log("polling... ");
            $.get("/get_compilation_status/", {'run_id' : run_id}, function(compilation_status_data){
                console.log(compilation_status_data);
                //clearInterval(interval);
                if(compilation_status_data["status"] != "QUEUED"){
                    clearInterval(interval);
                    $("#compilation_result").show();

                    $.get("/get_compilation_result", {'run_id' : run_id}, function(compilation_result_data){
                        $("#compilation_result").html(compilation_result_data);
                    });
                    $("#compile_and_test").removeAttr('disabled');
                    $("#loading_spinner").hide();
                }
            });
        }
    });
});


$(".language-select-menu-item").on("click", function() {
    var selText = $(this).text();
    $(this).parents('.btn-group').find('#selected-language').html(selText+' <span class="caret"></span>');
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
