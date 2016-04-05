# -*- coding: utf-8 -*-
# Generated by Django 1.9.2 on 2016-04-05 07:32
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('backend', '0018_auto_20160405_0440'),
    ]

    operations = [
        migrations.AddField(
            model_name='submission',
            name='statusDetail',
            field=models.TextField(default=None, null=True, verbose_name=b'Signal like SIGSEGV, NZEC ...'),
        ),
        migrations.AddField(
            model_name='submission',
            name='stderr',
            field=models.TextField(default=None, null=True, verbose_name=b'Stderr used when run time error happens'),
        ),
    ]
