# -*- coding: utf-8 -*-
# Generated by Django 1.9.2 on 2016-03-29 07:20
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('backend', '0007_submission_failedcase'),
    ]

    operations = [
        migrations.AddField(
            model_name='submission',
            name='expected',
            field=models.TextField(default=None, null=True, verbose_name=b'Expected outcome for failed test case'),
        ),
        migrations.AddField(
            model_name='submission',
            name='obtained',
            field=models.TextField(default=None, null=True, verbose_name=b'Obtained outcome for failed test case'),
        ),
    ]