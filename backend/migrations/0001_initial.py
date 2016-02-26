# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Problem',
            fields=[
                ('problem_id', models.IntegerField(serialize=False, primary_key=True)),
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
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Problem_Functions',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('c_code', models.TextField()),
                ('c_main_code', models.TextField()),
                ('cpp_code', models.TextField()),
                ('cpp_main_code', models.TextField()),
                ('java_code', models.TextField()),
                ('java_main_code', models.TextField()),
                ('problem', models.ForeignKey(to='backend.Problem')),
            ],
            options={
                'db_table': 'Problem_Functions',
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Submission',
            fields=[
                ('run_id', models.IntegerField(serialize=False, primary_key=True)),
                ('user_id', models.IntegerField()),
                ('source_code', models.TextField()),
                ('submission_time', models.DateTimeField()),
                ('status', models.CharField(max_length=50)),
                ('language', models.CharField(max_length=20)),
                ('issubmission', models.BooleanField(default=False)),
                ('compiler_error_log', models.TextField()),
                ('time_taken', models.IntegerField()),
                ('exit_code', models.IntegerField()),
                ('problem', models.ForeignKey(to='backend.Problem')),
            ],
            options={
                'db_table': 'Submission',
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Submission_unitrun',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('time_taken', models.IntegerField()),
                ('exit_code', models.IntegerField()),
                ('output', models.TextField()),
                ('result', models.CharField(max_length=100)),
                ('testcase_no', models.IntegerField()),
                ('Submission', models.ForeignKey(to='backend.Submission')),
            ],
            options={
                'db_table': 'Submission_unitrun',
            },
            bases=(models.Model,),
        ),
    ]
