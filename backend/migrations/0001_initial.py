# -*- coding: utf-8 -*-
# Generated by Django 1.9.2 on 2016-03-09 08:54
from __future__ import unicode_literals

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Problem',
            fields=[
                ('problem_id', models.IntegerField(primary_key=True, serialize=False)),
                ('title', models.CharField(max_length=100)),
                ('previewtext', models.TextField()),
                ('content', models.TextField()),
                ('types', models.TextField()),
                ('companies', models.TextField()),
                ('totalsubmission', models.IntegerField()),
                ('passedsubmissions', models.IntegerField()),
                ('difficulty', models.IntegerField()),
                ('time_limit_per_test_case', models.IntegerField()),
                ('memory_limit_per_test_case', models.IntegerField()),
                ('sample_test_cases_count', models.IntegerField()),
                ('test_cases_count', models.IntegerField()),
                ('is_driver_enabled', models.BooleanField(default=False)),
            ],
            options={
                'db_table': 'Problem',
            },
        ),
        migrations.CreateModel(
            name='Problem_Functions',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('c_code', models.TextField()),
                ('c_main_code', models.TextField()),
                ('cpp_code', models.TextField()),
                ('cpp_main_code', models.TextField()),
                ('java_code', models.TextField()),
                ('java_main_code', models.TextField()),
                ('problem', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='backend.Problem')),
            ],
            options={
                'db_table': 'Problem_Functions',
            },
        ),
        migrations.CreateModel(
            name='Submission',
            fields=[
                ('run_id', models.IntegerField(primary_key=True, serialize=False)),
                ('user_id', models.IntegerField()),
                ('source_code', models.TextField()),
                ('submission_time', models.DateTimeField()),
                ('status', models.CharField(max_length=50)),
                ('language', models.CharField(max_length=20)),
                ('issubmission', models.BooleanField(default=False)),
                ('compiler_error_log', models.TextField()),
                ('time_taken', models.IntegerField()),
                ('exit_code', models.IntegerField()),
                ('problem', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='backend.Problem')),
            ],
            options={
                'db_table': 'Submission',
            },
        ),
        migrations.CreateModel(
            name='Submission_unitrun',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('time_taken', models.IntegerField()),
                ('exit_code', models.IntegerField()),
                ('output', models.TextField()),
                ('result', models.CharField(max_length=100)),
                ('testcase_no', models.IntegerField()),
                ('Submission', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='backend.Submission')),
            ],
            options={
                'db_table': 'Submission_unitrun',
            },
        ),
    ]
