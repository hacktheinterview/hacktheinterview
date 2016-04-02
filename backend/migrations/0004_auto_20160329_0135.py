# -*- coding: utf-8 -*-
# Generated by Django 1.9.2 on 2016-03-29 01:35
from __future__ import unicode_literals

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('backend', '0003_auto_20160329_0134'),
    ]

    operations = [
        migrations.CreateModel(
            name='ProblemFunction',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('language', models.CharField(choices=[(b'1', b'C++'), (b'10', b'Java'), (b'4', b'Python'), (b'35', b'Javascript')], max_length=255)),
                ('header', models.TextField()),
                ('userSkeleton', models.TextField()),
                ('runnerFunction', models.TextField()),
                ('problem', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='problemFunctions', to='backend.Problem')),
            ],
        ),
        migrations.RemoveField(
            model_name='problemfunctions',
            name='problem',
        ),
        migrations.DeleteModel(
            name='ProblemFunctions',
        ),
    ]