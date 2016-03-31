$(document).ready(function(){
    var c_editor = ace.edit("c_editor");
    c_editor.setTheme("ace/theme/twilight");
    c_editor.getSession().setMode("ace/mode/javascript");
    c_editor.setShowPrintMargin(false);
    c_editor.getSession().setUseWrapMode(true);
    c_editor.getSession().setUseWorker(false);
    document.getElementById('c_editor').style.fontSize = '15px';

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

$("#twilight").click(function(e) {
    var c_editor = ace.edit("c_editor");
    c_editor.setTheme("ace/theme/twilight");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});

$("#monokai").click(function(e) {
    var c_editor = ace.edit("c_editor");
    c_editor.setTheme("ace/theme/monokai");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});

$("#chrome").click(function(e) {
    var c_editor = ace.edit("c_editor");
    c_editor.setTheme("ace/theme/chrome");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});

$("#xcode").click(function(e) {
    var c_editor = ace.edit("c_editor");
    c_editor.setTheme("ace/theme/xcode");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});

$("#crimson_editor").click(function(e) {
    var c_editor = ace.edit("c_editor");
    c_editor.setTheme("ace/theme/crimson_editor");
    var selText = $(this).text();
    $(this).parents('.btn-group').find('.dropdown-toggle').html(selText+' <span class="caret"></span>');
});
